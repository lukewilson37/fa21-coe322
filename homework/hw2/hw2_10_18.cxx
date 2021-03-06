#include<iostream>
#include<cmath>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

int main(){
  std::vector<int> v = { 1, 4, 9, 16, 25, 36, 49, 64};
  
  int sum_even_elements = 0;
  for(int i = 0; i < v.size(); i++){
    if (v[i] % 2 == 0){
      sum_even_elements = sum_even_elements + v[i];
    }
  }
  
  int i = 0;
  int sum_even_indicies = 0;
  while(2*i < v.size()){
    sum_even_indicies = sum_even_indicies + v[2*i];
    i++;
  }

  cout << "Sum of even elements: " << sum_even_elements << endl;
  cout << "Sum of even indicies: " << sum_even_indicies << endl;

  return 0;
}
