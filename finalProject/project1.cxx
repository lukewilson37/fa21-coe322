#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

#include<algorithm>

using std::reverse;

class address {
public:
  float i,j;
  int delivery_day;
  address() {}
  address(float x, float y) { i = x, j = y; };
  float distance(address ad2) {
    return sqrt(pow(i - ad2.i,2) + pow(j - ad2.j,2));
  };  
};

class addressList {
public:
  vector<address> alist;
  addressList(vector<address> initial_list) { alist = initial_list; };
  addressList() {};
  void add_address(address a1){ alist.push_back(a1); };
  float length() {
    int len = 0;
    for(int i = 1; i < alist.size(); i++){ len += alist[i-1].distance(alist[i]); };
    return len;
  };
  int index_closest_to(address a1){
    int closest_index = 0;
    float min_length = a1.distance(alist[0]);
    for(int i = 1; i < alist.size(); i++){
      if(a1.distance(alist[i]) < min_length) {
	min_length = a1.distance(alist[i]);
	closest_index = i;
      };
    }; 
    return closest_index;
  };
  //void remove_by_index(int index){ alist.erase(index); };
};

class route {
public:
  vector<address> route_list;
  //public:
  route() { route_list.push_back(address(0,0)); };
  route(addressList al){ 
    route_list.push_back(address(0,0)); 
    address potential_address;
    for (int i = 0; i < al.alist.size(); i++){
      potential_address = al.alist[i];
      bool unique = true;
      for (int j = 0; j < route_list.size(); j++) {
	if(potential_address.distance(route_list[j]) == 0) { unique = false; };
      };
      if(unique) { route_list.push_back(potential_address); };
    };
    route_list.push_back(address(0,0));
  };

  float length() {
    float len = 0;
    for (int i = 1; i < route_list.size(); i++ ) {
      len += route_list[i-1].distance(route_list[i]);
    };
    return len;
  }

  void add_address(address a1) {
    for (int i = 0; i < route_list.size(); i++) { if ( a1.distance(route_list[i]) == 0 ) { break; };};
    route_list[route_list.size() -1] = a1;
    route_list.push_back(address(0,0));
  };

  route greedy() {
    route greedy;
    int index_to_add;
    addressList r_ads = addressList(route_list);
    r_ads.alist.erase(r_ads.alist.end());
    while( r_ads.alist.size() > 0 ) { 
      index_to_add = r_ads.index_closest_to(route_list.back());
      greedy.add_address(r_ads.alist[index_to_add]);
      r_ads.alist.erase(r_ads.alist.begin()+index_to_add);
    };
    return greedy;
  };

  void display_route() {
    for(int n = 0; n < route_list.size(); n++) {
      cout << route_list[n].i << "," << route_list[n].j << endl;
    };
  };

  route opt2() {
    route potential_route, new_route(route_list);
    int route_size = new_route.route_list.size();
    for (int a = 1; a < route_size - 3; a++ ){
      for ( int b = a + 3; b < route_size; b++) {
	potential_route = new_route;
	reverse(potential_route.route_list.begin()+a+1, potential_route.route_list.begin() + b-1);
	if ( potential_route.length() < new_route.length() ) { new_route = potential_route; };
      };
    };
    return new_route;
  };
};
/**
int main() {
  vector<address> addlist = {address(6,5),address(5,8),address(3,0),address(6,2)};
  addressList test_al(addlist);
  test_al.add_address(address(8,2));

  route test_route(test_al);
  //  cout << test_al.index_closest_to(address(0,0));
  test_route.display_route();
  
  return 0;
}
**/
