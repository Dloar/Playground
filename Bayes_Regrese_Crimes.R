# R kod pro pro Bayesovsky odhad parametru regresniho modelu - crimes data
# autor: MP
# model: y_t = b0 + b1*X1 + b2*X2 + b3*X3 +b4*X4 + b5*X5 u_t   (b0 az b5 - regresni parametry, u_t = nahodna slozka)
# import dat probiha ze souboru s priponou csv


# ----------- PRIPRAVA DAT -------------------------------------------------------------------------------------------------------
data <- data.matrix(read.csv2("Documents/Crimes_data.csv"))  #zmenit cestu podle vlastniho umisteni souboru
nObs <- nrow(data) #pocet pozorovani v modelu
# konstrukce promennych vystupujicich v modelu
y <- data[,1]  # y_t - zavisla promenna
X <- cbind(rep(1,nObs), data[,2:ncol(data)]) #matice X vcetne konstanty


# --------- VSTUPNI (POMOCNE) VYPOCTY --------------------------------------------------------------------------------------------
# Odhad parametru metodou OLS (metoda nejmensich ctvercu) - pouzito jako pocatecni hodnoty pro Gibbsuv vzorkovac
Bols <- solve(t(X)%*%X) %*% t(X) %*% y  # odhad regresnich parametru (X'X)^-1*X'y
S2ols <- (t(y- X%*%Bols) %*% (y- X%*%Bols))/(nObs-6)  #odhad roztylu  e'e/n-p.. e=rezidua, nObs = pocet pozorovani, p = pocet parametru

#--------------- PRIORS - formulace apriorniho rozdeleni regresnich parametru a rozptylu----------------------------------------------
# regresni parametry ~ N(b0,Varb0)
b0 <- c(2,-.30,-.20,.30,.05,.40)  # lze libovolne menit
Varb0 <- diag(c(.005,rep(.005,5))) # lze libovolne menit
# rozptyl nahodne slozky ~ IG(T0/2, D0/2) (inverzni gama rozdeleni - parametry lze menit)
T0 <- 1
D0 <- 0.1 #Ocekavam plochy gamma dist.

# -------------- GIBBS SAMPLER/GIBBSUV VZORKOVAC (GS) ------------------------------------------------------------
nGibbs <- 5000  # celkovy pocet kol Gibbsova vzorkovace
nBurn <- 3000    # pocet zahozenych vzorku na zacatku - sekvenci parametru lze pro inferenci vzit az po konvergenci
bMat <- matrix(NA,nrow = (nGibbs-nBurn), ncol = 6)   # matice pro ukladani vysledku - regr. param. (jednotlive tahy z GS)
# Ulkada jednotlive tahy
SMat <- numeric() #  vektor pro ukladani vysledku - roztpyl (jednotlive tahy z GS)
Sigma <- as.numeric(S2ols) # pocatecni hodnota rozptylu pro GS (hodnota se rovna odhadu z OLS)

for (i in 1:nGibbs)
{
  #Zacatek cyklu pro gibsuv sample
  # 1. samplovani hodnoty parametru z posteriorniho (podmineneho) za predpokladu, ze rozptyl (Sigma) je znam
  # Podminene posteriorni rozdeleni regresnich parametru je normalni ~ N(Mstar,Vstar)
  
  # a) vypocet hodnoty parametru posteriorniho rozdeleni Mstar, Vstar
  #Mstar (stredni hodnota) = (Varb0^-1 + 1/Sigma*X'X)*(Varb0^-1*b0 + (1/Sigma)*X'y)
  #Vstar (rozptyl) = (Varb0^-1 + 1/Sigma*X'X)
  
  Mstar <- solve(solve(Varb0) + (1/Sigma)*(t(X)%*%X)) %*% (solve(Varb0)%*%b0 + (1/Sigma)*(t(X)%*%y))
  # odpovida ni*
  Vstar <- solve(solve(Varb0) + (1/Sigma)*(t(X)%*%X))
  #odpovida kovariancni matici
  # b) samplujeme jednu nahodnou hodnotu z daneho vicerozmerneho normalniho rozdeleni
 
  # tazeni nahodneho vyberu z vicerozmerneho normalniho rozdeleni
  b <- Mstar + t(rnorm(ncol(X))%*%chol(Vstar)) # tazeni nahodneho vyberu z vicerozmerneho normalniho rozdeleni

  # 2. generovani hodnoty pro rozptyl, jehoz podminene posteriorni rozdeleni je inverzni Gama ~ IG(T1/2, D1/2)
  # podminene je vzhledem ke "znamym" hodnotam regresnich parametru Beta (ulozenych v GS pod promennou b) 

  # a) Stanoveni parametru posteriorniho rozdeleni
  T1 <- T0+nObs
  D1 <- D0 + (t(y- X%*%b) %*% (y- X%*%b))   # D1 = D0 + e'e
  # b) Generovani nahodneho cisla z posteriorniho rozdeleni
  z0 <- rnorm(T1)  
  Sigma <- as.double(D1/(t(z0)%*%z0))
  
  # ulozeni vektoru parametru z aktualniho kola GS - po zahozeni prvnich nBurn vzorku
  if (i > nBurn)
  {
    bMat[i-nBurn,] <- b
    SMat[i-nBurn] <- Sigma
  }

}
# konec cyklu pro Gibbsuv vzorkovac


# generovani nekterych vysledku  -----------------------------------------------------------------------------------------------

# bodove odhady regresnich parametru
Bbay <- apply(bMat,2,median)  

# intervalove odhady
apply(bMat,2, function(x) quantile(x,0.05)) # 5% kvantil
apply(bMat,2, function(x) quantile(x,0.95)) # 95% kvantil

# histogram marginalniho posteriorniho rozdeleni pro jednotlive parametry (na zaklade GS)
par(mfrow=c(3,2))
hist(bMat[,1], breaks = 30, xlab = "konstanta", main = "")  # konstanta
hist(bMat[,2], breaks = 30, xlab = "Beta_1", main = "")  # parametr b1, 
hist(bMat[,3], breaks = 30, xlab = "Beta_2", main = "")  # parametr b2,
hist(bMat[,4], breaks = 30, xlab = "Beta_3", main = "")  # parametr b3,
hist(bMat[,5], breaks = 30, xlab = "Beta_4", main = "")  # parametr b4, 
hist(bMat[,6], breaks = 30, xlab = "Beta_5", main = "")  # parametr b5
par(mfrow=c(1,1))
# overeni MCMC retezce
plot(bMat[,1], type = "l")

hist(SMat, breaks = 30)   # rozptyl nahodne slozky

# fit modelu
plot(y - X%*%Bols, pch = 20, ylim = c(-10,10), ylab = "")  # in sample fit pomoci OLS
abline(0,0)
par(new = T)
plot(y - X%*%Bbay, pch = 20, ylim = c(-10,10), col = 4, ylab = "")  # in sample fit pomoci bayesovske regrese

