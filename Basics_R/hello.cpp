#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
List pack_boxes(int n, NumericVector p) {
  Function sample = Environment("package:base")["sample"];

  // Sample item weights.
  int w = p.size();
  IntegerVector item = sample(w, n, true, p);
  // Initialize loop variables.
  IntegerVector weight(n);
  weight[0] = item[0];
  IntegerVector first(n);
  first[0] = 1;
  int n_boxes = 1;
  for (int i = 1; i < n; i++) {
    int new_weight = weight[i - 1] + item[i];
    if (new_weight <= w) {
      // Continue with current box.
      weight[i] = new_weight;
    } else {
      // Start a new box.
      weight[i] = item[i];
      first[n_boxes++] = i + 1;
    }
  }
  return List::create(
    _["item"] = item,
    _["weight"] = weight,
    _["first"] = first[seq(0, n_boxes - 1)]
  );
}
