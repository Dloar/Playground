library(Rcpp)
sourceCpp("hello.cpp")

set.seed(256)
pack_boxes(10, c(0, 0.7, 0.2, 0.1))
