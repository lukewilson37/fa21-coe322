#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#include<vector>

#include<time.h>

using std::vector;

#include<algorithm>

using std::reverse;

#include"project1.cxx"

route gen_rand_route(int n,int width){
  vector<address> rand_route_list;
  int x,y;
  for (int i = 0; i < n; i++){
    x = rand() % (width +1) - (width/2);
    y = rand() % (width + 1) - (width/2);
    rand_route_list.push_back(address(x,y));
  }
  return route(rand_route_list);
}

void randomize_delivery_days(route &route1, int within_days, int today){
  for (int i = 0; i < route1.route_list.size(); i++){
    route1.route_list[i].delivery_day = rand() % within_days + today;
  }
}

void two_routes_length(route r1, route r2){
  cout << "Length of 2 routes: " << r1.length() + r2.length() << endl;
}

void optimize_two_prime_routes(route &route1, route &route2){
  route pot_route1(route1.route_list);
  route pot_route2(route2.route_list);
  address holder;
  for (int i = 1; i < route1.route_list.size() - 1; i++){
    while (route1.route_list[i].delivery_day == 0 ){i++;};
    for (int j = 1; j < route2.route_list.size() - 1; j++){
      while(route2.route_list[j].delivery_day == 0 ){j++;};
      holder = pot_route1.route_list[i];
      pot_route1.route_list[i] = pot_route2.route_list[j];
      pot_route2.route_list[j] = holder;

      if(pot_route1.length() + pot_route2.length() < route1.length() +route2.length()){
	route1 = pot_route1;
	route2 = pot_route2;
      }else{
	pot_route1 = route1;
	pot_route2 = route2;
      }
    } 
  }

}
void swap_if_shorter_routes(route &r1, route &r2, route pr1, route pr2){
  if (pr1.length() + pr2.length() < r1.length() + r2.length()){
    r1 = pr1;
    r2 = pr2;
    //cout << "swapped" << endl;
  }
}

void optimize_two_routes(route &route1, route &route2){
  int n1 = route1.route_list.size();
  int n2 = route2.route_list.size();
  int b1,b2;
  route pot_route1(route1.route_list);
  route pot_route2(route2.route_list);

  for(int a1 = 0; a1 < n1 - 3; a1++){
    b1 = a1 + 3;
      
    for (int a2 = 0; a2 < n2 - 3; a2++){
      int b2 = a2 + 3;
      
      vector<address> pot_list1 = pot_route1.route_list;
      //Swap route segments
      pot_route1.route_list.insert(pot_route1.route_list.begin() + a1+1,
				   pot_route2.route_list.begin() + a2 +1, pot_route2.route_list.begin() + b2-1);
      
      pot_route2.route_list.insert(pot_route2.route_list.begin() + a2+1,pot_list1.begin() + a1+1, pot_list1.begin() + b1-1);
      
      pot_route1.route_list.erase(pot_route1.route_list.begin() + (b2-a2-2) + a1+1,
				  pot_route1.route_list.begin() + (b2 - a2-2) + b1-1);
      
      pot_route2.route_list.erase(pot_route2.route_list.begin() + (b1 - a1-2) + a2+1,
				  pot_route2.route_list.begin() + (b1 - a1-2) + b2-1);
      
      swap_if_shorter_routes(route1,route1,pot_route1,pot_route2);
      //reverse route 1 segment
      reverse(pot_route1.route_list.begin() + a1+1,pot_route1.route_list.begin() + a1+1 + (b2-a2-2));
      
      swap_if_shorter_routes(route1,route2,pot_route1,pot_route2);
      //reverse route 2 segment
      reverse(pot_route2.route_list.begin()+a2+1,pot_route2.route_list.begin() + a2 + 1+(b1-a1-2));
      
      swap_if_shorter_routes(route1,route2,pot_route1,pot_route2);
      //reverse route 1 segment, so that only route 2 is reversed
      reverse(pot_route1.route_list.begin() +a1+1,pot_route1.route_list.begin() + a1 + (b2-a2-2));
      
      swap_if_shorter_routes(route1,route2,pot_route1,pot_route2);
            
      
    }
  }
}

void simulate_days(route the_route, int days, int width_of_town, int max_num_new_dels, int &overtime){
  float work_day_length = 10;
  float speed = 300;

  route new_deliveries;
  route todays_route;
  route todays_potential_route;

  for (int day = 0; day < days; day++){ 
    todays_route = route(addressList({address(0,0),address(0,0)}));
    new_deliveries = gen_rand_route(rand() % 100 + max_num_new_dels + 1, width_of_town);
    randomize_delivery_days(new_deliveries,days,day);
    
    for (int a = 0; a < new_deliveries.route_list.size(); a++){
      the_route.add_address(new_deliveries.route_list[a]);
    }
        
    for(int i = 1; i < the_route.route_list.size()-1; i++ ){
      if(the_route.route_list[i].delivery_day == day){
	todays_route.add_address(the_route.route_list[i]);
	the_route.route_list.erase(the_route.route_list.begin()+i);
      }
    }
    
    todays_potential_route = todays_route;
    
    todays_route = todays_route.opt2();
    
    if(todays_route.length() > work_day_length*speed){ overtime++; };

    cout << todays_route.route_list.size() << " todays route: " << todays_route.length() << endl;
    //todays_route.display_route();
  }
}
