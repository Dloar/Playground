
lapply(1:5, function(x) x^2) 
lapply(1:5, function(x) c(x^2,x^3)) 

sapply(1:5, function(x) x^2, simplify = FALSE, USE.NAMES = FALSE)
sapply(1:5, function(x) x^2) 
sapply(1:5, function(x) c(x^2,x^3)) 

# Parallel

install.packages("parallel")
library(parallel)

# clusterEvalQ() function
clusterEvalQ(clust,library(randomForest))

# doParallel & foreaech
install.packages("doParallel")
library(doParallel)
install.packages("foreach")
library(foreach)

foreach(exponent = 1:5, .combine = c)  %dopar%  base^exponent
registerDoParallel(no_cores)
