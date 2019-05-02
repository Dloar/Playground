library("MASS")
str(Boston)

y <- Boston$medv
X <- as.matrix(Boston[-ncol(Boston)])
int <- rep(1, length(y))

X <- cbind(int, X)
betas <- solve(t(X) %*% X) %*% t(X) %*% y
betas
