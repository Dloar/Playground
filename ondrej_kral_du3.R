rm(list = ls())

#install.packages("gdata")
#library(gdata)

#Nacteni dat
CHL   = read.xls("~/Desktop/du3_OK.xls")
# nacist data do matice a nahradit NA nulama
chl = as.matrix(CHL, row.names = 1)
  chl[is.na(chl)] = 0 #Replace all NA's by 0
    n =nrow(chl)

  dataset = t(apply(chl,1,cumsum)) # Udelam z toho kumulativni matici
# trojuhelniik bez diagonaly
  # Cely tohle dostava data, kde u jednoho je diagonala  u druheheho ne.

tri_ND = upper.tri(dataset,diag = FALSE) # 2 trojuhelniky, kde na diagonale mam FALSE
  tri_ND = tri_ND[,n:1] # trojuhelniky otocim
# Trojuhlenik s diagonalou
tri_WD = upper.tri(dataset,diag = TRUE)
  tri_WD = tri_WD[,n:1]
#nastavim, aby tam, kde je FALSE byla nula a tam kde neni, tak aby to vzalo hodnoty z z dataset matice
  dataset[!tri_WD] = 0

fac = matrix(0,n,n) # Matice nul o velikosti n*n
  fac[tri_ND] = dataset[tri_ND] # Tam kde jsou true, dam data z matice dataset (bez diagonaly)
    fac =fac[,-n]
      fac1 = dataset[,-1]
# udelam sumu sloupcu a vydelim je navzajem. 
a =colSums(fac1)
b =colSums(fac)

  FAC = a/b
    rm(fac1, fac,a,b)
#Vzhledem k tomu, ze fac je vetsi nez fac1, tak musim z FAC odstarnit podledni sloupec, ktery sem nicim nedelil.
FAC = FAC[1:(n-1)]
# Do kazdeho sloupce da hodnoty, ktere jsme vypocitali ve FAC (pouze pro n-1 radku)
devrep =(matrix(rep(FAC,n-1),nrow = n-1,byrow = T))

devrep[tri_WD[-1,-1]] = 1 # Kde je v matici tri_WD TRUE, tak tam nahradim hodnotu jednickou
  devrep_cumu = t(apply(devrep,1,cumprod)) # Prevedu na kum....
  #devrep_cumu1 = apply(devrep,1,cumprod)
  #devrep_cumu1 = t(devrep_cumu1)
    

dia_v = dataset[,n:1] # Zmenim poradi datasetu
  dia_v = diag(dia_v) # Diagonala z dia
    dia_v = matrix(dia_v[-1],n-1,n-1)

clFinal = dia_v * devrep_cumu

