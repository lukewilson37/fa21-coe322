#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

using std::endl;
using std::cout;
using std::vector;
using std::cin;
using std::setw;

class pascal {
private:
  int row;
  vector<vector<int>> triangle;
public:
  pascal( int row_in ) {
    row = row_in;
    triangle = vector<vector<int>>(row,vector<int>(row));
    for (int i = 0; i < row; i++){
      triangle.at(i).at(0) = 1;
      triangle.at(i).at(i) = 1;
      for(int j = 1; j < i; j++){
	triangle.at(i).at(j) = triangle.at(i-1).at(j-1) + triangle.at(i-1).at(j);
      };
    };
  };
  int get( int i, int j ) {
    return triangle.at(i-1).at(j-1);
  };
  void print(){
    for (int i = 1; i <= row; i++){
      cout << "Row " << setw(4) << i << ":";
      cout << setw(row*3 - (i-1)*3) << " ";
      for (int j = 1; j <= i; j++){
	cout << setw(6) << triangle.at(i-1).at(j-1);
      }
      cout << endl;
    }
  }
  void print(int m){
    for (int i = 1; i <= row; i++){
      cout << setw(9 + 3*row - (i-1)*3) << " ";
      for (int j = 1; j <= i; j++){
	cout << setw(6);
	if( triangle.at(i-1).at(j-1) % m == 0){
	  cout << " ";
	} 
	if( triangle.at(i-1).at(j-1) % m != 0 ) {
	  cout << "*";
	}
      }
      cout << endl;
    }
  }
};

int main() {
  
  
  int r;
  cin >> r;
  pascal tri(r); 
  int m;
  while(cin >> m){
    tri.print(m);
  }
  /*
  int r, c;
  cin >> r >> c;
  cout << endl;
  cout << poop.get(r,c) << endl;
  */
  return 0;
}
