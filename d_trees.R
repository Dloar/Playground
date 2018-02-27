#install.packages("rpart")
#library(rpart)
cat('\f')
rm(list = ls())
#### rpart ####
raw.orig =  read.csv("~/Downloads/rsei212_chemical.txt", header=T, sep="\t")
raw = subset(raw.orig, select=c("Metal","OTW","AirDecay","Koc"))

row.names(raw) = raw.orig$CASNumber
raw = na.omit(raw);

frmla = Metal ~ OTW + AirDecay + Koc

# Metal: Core Metal (CM); Metal (M); Non-Metal (NM); Core Non-Metal (CNM)

fit = rpart(frmla, method="class", data=raw)

printcp(fit) # display the results
plotcp(fit) # visualize cross-validation results
summary(fit) # detailed summary of splits

# plot tree
plot(fit, uniform=TRUE, main="Classification Tree for Chemicals")
text(fit, use.n=TRUE, all=TRUE, cex=.8)

# tabulate some of the data
table(subset(raw, Koc>=190.5)$Metal)
####Tree####
#install.packages("tree")
#library("tree")
tr = tree(frmla, data =  raw)
plot(tr)
text(tr)
summary(tr)

#######Random Forest###########
#install.packages("randomForest")
#library(randomForest)
fit.rf = randomForest(frmla, data=raw)
print(fit.rf)
importance(fit.rf)
plot(fit.rf)
plot( importance(fit.rf), lty=2, pch=16)
lines(importance(fit.rf))
imp = importance(fit.rf)
impvar = rownames(imp)[order(imp[, 1], decreasing=TRUE)]
op = par(mfrow=c(1, 3))
for (i in seq_along(impvar)) {
  partialPlot(fit.rf, raw, impvar[i], xlab=impvar[i],
              main=paste("Partial Dependence on", impvar[i]),
              ylim=c(0, 1))
}

