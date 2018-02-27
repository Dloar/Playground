rm(list = ls())
cat("\f")
#install.packages("Amelia")
library("Amelia")
titanic <- read.csv("~/Downloads/train.csv")
training = read.csv("~/Downloads/train.csv", na.strings = c(""))
sapply(training,function(x) sum(is.na(x)))
sapply(training,function(x) length(unique(x)))
missmap(training, main = "Missing values")
data = subset(training, select =c(2,3,5,6,7,8,10,12))
data$Age[is.na(data$Age)] = mean(data$Age, na.rm = T)
is.factor(data$Survived)
contrasts(data$Embarked)

data <- data[!is.na(data$Embarked),]
rownames(data) <- NULL

###Data Split
train = data[1:800,]
testing = data[801:889,]

###Model
fit1 = glm(Survived ~ ., family = binomial(link = "logit"), data = train)
summary(fit1)

anova(fit1, test="Chisq")

install.packages("pscl")
library(pscl)
pR2(fit1)

fitted.results <- predict(fit1,newdata=subset(testing,select=c(2,3,4,5,6,7,8)),type='response')
misClasificError <- mean(fitted.results != testing$Survived)
print(paste('Accuracy',1-misClasificError))

library(ROCR)
p <- predict(fit1, newdata=subset(testing,select=c(2,3,4,5,6,7,8)), type="response")
pr <- prediction(p, testing$Survived)
prf <- performance(pr, measure = "tpr", x.measure = "fpr")
plot(prf)

auc <- performance(pr, measure = "auc")
auc <- auc@y.values[[1]]
auc
