# Reinsurance Value

rm(list = ls()) #clear
cat(rep("\n",128)) #quick and dirty clear console
setwd("C:/Users/John/Desktop/Homo7/")
set.seed(500)                # nastavi fixni pocatek generatoru

# Inputs ____________________________________________________________

lmb <-911                    # stredni hodnota rocniho poctu PU
mu <- 6.765574               # stredni vyse log skody
sig <- 1.168573              # smerodatna odchylaka log skody

prior_xl = 10000             # Vyse zajisteni
VARq <- 0.99                 # Quantile
sim <- 5000                  # pocet scenaru

Zajistne <- 115000
SazbaKap <- 0.06



# Calculation _______________________________________________________
res <-matrix(0,sim,1)        # vytvori vektor vysledku
res_xl <-matrix(0,sim,1)     # vytvori vektor vysledku po XL zajisteni
n<-matrix(0,sim,1)           # vytvori vektor skod 
n<-rpois(sim,lmb);           # generuje pocty skod (pro vsechny scenare)

for(i in 1:sim) {
    
    x<-rlnorm(n[i], meanlog = mu, sdlog = sig)        # vygeneruje jednotlive skody
    x_xl<-pmin(x,prior_xl)                            # spocte vlastni vrub (odecte podil zajistitele)
    res[i] <- sum(x)                                  # agreguje skody a ulozi
    res_xl[i] <- sum(x_xl)                            # agreguje skody po xl zajisteni a ulozi
    
}

# Stats _____________________________________________________________
KapPozad_ReInsur = as.numeric( quantile(res_xl, VARq) - mean(res_xl))
KapPozad_None = as.numeric( quantile(res, VARq) - mean(res))
UsetreneNaklady = (KapPozad_None - KapPozad_ReInsur) * SazbaKap
TechVys = (mean(res) - mean(res_xl)) - Zajistne
BenefitOfReinsur = UsetreneNaklady + TechVys                       # Kladna hodnota znacipridanou hodnotu zajisteni


x_lim = c(1200000, 2000000)
hist_stp <- hist(res, freq = F,breaks =10, xlim = x_lim)           # hist without reinsurance
hist(res_xl,freq = F,breaks =10, add=TRUE, col=rgb(0, 1, 0, 0.5))  # hist including reinsurance


#write.table(res, file = "res.csv", sep = ";", dec = ",", row.names=FALSE) #export to csv
#write.table(cbind(res, res_xl), file = "res_xl.csv",  sep = ";", dec = ",", row.names=FALSE)
