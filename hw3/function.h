// Functions File Yay

#include<iostream>
#include<cmath>
#include<iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

double f(int n) { return (n*n) + 1; };

int increment_positive_only(int n) { return n+1; };

vector<double> set_coefficients() {
  vector<double> vec = {1,2,3,4};
  return vec;
}

bool proper_polynomial( vector<double> coefficients){
  if( coefficients.empty()){ return false; }
  if( coefficients.front() == 0 ){ return false; }

  return true;
}

double evaluate_at( vector<double> coefficients, double x){
  double y = 0;
  for (int i = 0; i < coefficients.size(); i++){
    y += coefficients[i] * pow(x,coefficients.size() -1 - i);
  }
  return y;
}

bool is_odd(vector<double> coefficients){
  if( coefficients.size() % 2 == 0){ 
    return true; 
  }
  else{
    return false;
  }
}

vector<double> find_outer(vector<double> coefficients, double left, double right){

  if( not is_odd(coefficients) ){ exit(1); };
  double delta;
  while(evaluate_at(coefficients,left) * evaluate_at(coefficients,right) > 0){
    delta= right - left;
    right += delta;
    left += delta;
  }
  vector<double> vec{left,right};
  return vec;
}

double find_zero(vector<double> coefficients, double left, double right, double precision){
  if ( not is_odd(coefficients) ) { exit(1);};

  vector<double> left_right = find_outer(coefficients,left,right);
  left = left_right[0];
  right = left_right[1];
  double mid;

  while( abs(right-left) < precision){
    mid = (right + left)/2;
    if(evaluate_at(coefficients,mid) * evaluate_at(coefficients,left) > 0){ 
      right = mid;
    }else{
      left = mid;
    }
  }  
  return (left + right)/2;
}

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"
