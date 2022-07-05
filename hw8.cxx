#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<iomanip>
using std::fixed;
using std::setprecision;

#include<vector>
using std::vector;

#include<chrono>

#include<optional>
using std::optional;


class board {
private:
  vector<int> columns;
public:
  board(int n)
    : columns( vector<int>(n,-1) ) {};
  board( vector<int> cols )
    : columns(cols) {};
  board(int n, vector<int> cols )
    : columns( vector<int>(n,-1) ) {for(int i = 0; i <= cols.size();i++) {columns[i] = cols[i];};};
  int next_row_to_be_filled() {
    int next = 0;
    while (columns[next]>=0) {next++;};
    return next;
  };

  int place_next_queen_at_column( int c ) {
    if ( (c < 0) || (c > columns.size()-1) ) {throw(1);};
    int row = next_row_to_be_filled();
    columns[row] = c;
  };

  bool feasible() {
    int c, cj;
    for(int i = 1; i < columns.size(); i++){
      c = columns[i];
      if (c != -1) {
	for(int j = 0; j < i; j++){
	  cj = columns[j];
	  if(cj != -1) {if(cj == c or cj+i-j == c or cj-i+j == c) {return false;};};
	}
      }
    }
    return true;
  };
  bool filled() {
    for(int i = 0; i < columns.size(); i++) { if(columns[i] < 0) {return false;};};
    return true;
  };

  optional<board> place_queens() {
    for(int col = 0; col < columns.size(); col++) {
      board next = *this;
      next.place_next_queen_at_column(col);
      if (next.feasible()){
	if(next.filled()) {return next;};
	next.place_queens();
      };
     
    };
    return {};    
  };

  void show_board() {
    for (int i = 0; i < columns.size(); i++) {
      cout << columns[i] << " ";
    };
  };
};
/**
int main() {
  board trial(8);
  trial.show_board();
  if (not trial.feasible() ) { cout << "yeah" << endl;};
  auto solution = trial.place_queens();
  if( solution.has_value() ) {cout << "yes" << endl;};
  return 0;
}
**/
