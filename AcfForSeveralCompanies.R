### packages we will use
install.packages("quantmod")
install.packages("forecast")
library(quantmod)
library(forecast)

### some definitions
lag.max = 20 # for how many lags should the ACFs be calculated

### vector of DJI components
vecOfSymbs = c("AXP", "BA", "CAT", "CSCO", "CVX", "DD", "DIS", "GE", "GS", "HD", 
               "IBM", "INTC", "JNJ", "JPM", "KO", "MCD", "MMM", "MRK", "MSFT", "NKE", 
               "PFE", "PG", "T", "TRV", "UNH", "UTX", "V", "VZ", "WMT", "XOM")


### downloading the data for the tickers
dji = new.env() # the data will be stored in an environment called dji

getSymbols(vecOfSymbs, source = "yahoo", from = "2007-01-03", end = "2014-09-23")

ls(dji) # we list the names in the environment dji

### calculating the sample autocorrelation functions
acfMatrix = matrix(NA, length(vecOfSymbs), lag.max) # the sample autocorrelation functions will be save into a matrix called acfMatrix

counter = 0 # this variable will be used in the for loop below

for (i in vecOfSymbs) { # we iterate over all components
  counter = counter + 1
  
  actual = get(i, envir = dji) # we load the respective variable from the dji environment to a variable called actual
  pr = as.numeric(actual[ , 6]) # we extract adjusted close prices
  ret = diff(log(pr)) # we calculate log returns
  
  # we calculate the sample acf and save it into the respective row of the matrix acfMatrix
  acfMatrix[counter, ] = Acf(ret, lag.max = lag.max, plot = FALSE)$acf[2:21 , 1 , 1]
}

### we plot the results
# the boxplot for ACF values at individual lags
boxplot(acfMatrix, ylim = c(-1, 1)); abline(h = 0, lty = 3)
boxplot(acfMatrix); abline(h = 0, lty = 3) # we zoom into the figure

# the mean absolute value of ACF for individual lags
plot(1:lag.max, apply(abs(acfMatrix), 2, mean), type = "h") 

# we assign the autocorrelations to groups and calculate the frequencies for each group
groups = cut(acfMatrix, breaks = c(-1, -0.1, -0.05, 0, 0.05, 0.1, 1))

table(groups) # the frequencies in individual groups suggest that the autocorrelations are rather small

