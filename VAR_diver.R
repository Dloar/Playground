### Generuj dva vektory s vysi agregovane rezervy.
# Pocet skod je dan z poissonova rozdelene
# Nasledne vysi skody modeluj dle 1 s logaritmickym a po 2 s inverznim Gauss rozdelenim.
# Zadna zalozna a pripojisteni.

# PRIDANA HODNOTA DIVERZIFIAKCE
# SOUCET JEDNOTLIVYCH VAR JE NIZSI NEZ VAR SOUCTU INDIVIDUALNICH AGREG REZERV

install.packages("fitdistrplus")         #add describtive stats
library(fitdistrplus)

install.packages("statmod")
library(statmod)                         #add inverse gaussian distribution

rm(list = ls())
cat(rep("\n",128))
#setwd("C:/Users/John/Desktop/Homo7/")
set.seed(500)                     # nastavi fixni pocatek generatoru

# Inputs ____________________________________________________________

lmb =911                         # stredni hodnota rocniho poctu PU
mu = 6.765574                    # stredni vyse log skody
sig = 1.168573                   # smerodatna odchylka log skody

lmb2 = 82                         # stredni hodnota rocniho poctu PU
mu2 = 1915.75                     # stredni vyse log skody
lambdaig = 673.1276               # parametr vyse skody ("precision")

VARq = 0.99
sim = 5000                       # pocet scenaru

# Calculation _______________________________________________________
res =matrix(0,sim,2)             # vytvori vektor vysledku
n=matrix(0,sim,2)                # vytvori vektor skod  
n[,1]=rpois(sim,lmb);            # generuje pocty skod (pro vsechny scenare)
n[,2]=rpois(sim,lmb2);           # generuje pocty skod (pro vsechny scenare)


for(i in 1:sim) {
  
  x=rlnorm(n[i,1], meanlog = mu, sdlog = sig)         # vygeneruje jednotlive skody
  res[i,1] = sum(x)                                   # agreguje skody a ulozi
  x2=rinvgauss(n[i,2], mu = mu2, lambda = lambdaig)   # vygeneruje jednotlive skody
  res[i,2] = sum(x2)                                  # agreguje skody a ulozi
}

descdist(as.vector(res),graph = T)


### STAT diverzifikace ______________________________________________
res = as.data.frame(res)
res[,3] = res[,1] + res[,2]
names(res) = c("rlnorm","rinvgauss","total" )

VaR_Diver = as.numeric (quantile(res[,1], VARq ) + quantile(res[,2], VARq ))
Var_None = as.numeric( quantile(res[,3], VARq ) )

BenefitOfDiv = VaR_Diver - Var_None                    # Diverzifiakci snizime potrebne rezervy o tuto sumu



write.csv(res,file = "res_mult.csv", sep = ";", dec = ",", row.names=FALSE)
