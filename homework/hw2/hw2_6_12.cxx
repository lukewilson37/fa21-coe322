#include<iostream>

using std::cout;
using std::endl;

int main(){
  cout << "running" << endl;
  int max = 1;
  for (int i = 2; i < 1001; i++) {
    int iter = 1;
    int n = i;
    while( n > 1){
    
    if ( n % 2 == 0 ){
      n = n/2;
    }
    else {
      n = 3 * n + 1;
	}
    iter++;
    }
    if(iter > max){
      cout << i << endl;
      max = iter;
    }
  }

  return 0;
}
