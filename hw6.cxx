#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include<cmath>

#include<functional>
using std::function;

double find_zero(function< double(double) > f) {
  
  double h = 0.001;
  double fx;
  double fpx;
  double x1 = -f(0);
  
  while(true) {
    fx = f(x1);
    fpx  = (f(x1+h)-fx)/h;
    if(std::abs(fx/fpx) < 1.e-10) break;
    x1 = x1 - fx/fpx;
    //cout << x1 << endl;
  }

  return x1;
}

int main() {
  double x;
  while(cin >> x){
    double root = find_zero([x] (double x0) -> double { return x0*x0-x; });
    cout << root << endl;
  }
  return 0;
}
