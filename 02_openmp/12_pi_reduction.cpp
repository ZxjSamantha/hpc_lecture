#include <cstdio>
#include <omp.h>
// Test for submission
// The code shown below is the calculation of pi by the method of numeric integration. 
// The aim of the parallelization is to reduce the variable 'pi'.
int main() {
  omp_set_num_threads(4);
  int n = 10;
  double dx = 1. / n;
  double pi = 0;
  //lines 9-11 executes a predetermined number of iterations (n=10 in the initial case)
#pragma omp parallel for reduction(+:pi) schedule(static) 
  for (int i=0; i<n; i++) {
    double x = (i + 0.5) * dx;
    pi += 4.0 / (1.0 + x * x) * dx;
  }
  printf("%17.15f\n",pi);
}
