#include<iostream>
#include<cmath>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


#include"project1_functions.cxx"

void greedy_sim() {
  srand(time(NULL));
  float mean = 0, greedy_mean = 0;
  route r;
  for(int i = 0; i < 100000; i++){
    r = gen_rand_route(100,20);
    mean += r.length();
    r = r.greedy();
    greedy_mean += r.length();
  }
  mean = mean/100000;
  greedy_mean = greedy_mean/100000;

  cout <<"random mean: " << mean << endl << "greedy mean: " << greedy_mean << endl;
  cout << "percent change: " << (greedy_mean - mean) / mean << "%" << endl;
  
}

void opt2_vs_greedy_sim(){
  srand(time(NULL));

  float greedy_mean;
  float opt2_mean;

  route r;

  vector<int> nums = {10,20,50,100};
  vector<int> widths = {20,50,100,200};

  for(int i = 0; i < nums.size(); i++){
    for(int j = 0; j < widths.size(); j++){
      greedy_mean = 0;
      opt2_mean = 0;
      for (int k = 0; k < 10000; k++){
	r = gen_rand_route(nums[i],widths[j]);
	r = r.greedy();
	greedy_mean += r.length();
	r = r.opt2();
	opt2_mean += r.length();
      }
      greedy_mean = greedy_mean/10000;
      opt2_mean = opt2_mean/10000;
      cout << "num: " << nums[i] << " width: " << widths[j] << endl;
      cout << "greedy mean: " << greedy_mean << endl << "opt2 mean: " << opt2_mean << endl;
      cout << "opt2 " << - (opt2_mean - greedy_mean) / greedy_mean << " % more efficient than greedy" << endl << endl;
    }
  }
}

void opt2_two_routes_sim() {
  srand(time(NULL));
  route r1;
  route r2;

  float rand_mean;
  float opt2_mean;

  int iter = 1000;

  vector<int> nums = {10,20,50,100};
  vector<int> widths = {20,50,100,200};
  for(int n = 0; n < nums.size(); n++){
    for(int w = 0; w < widths.size(); w++){
      rand_mean = 0;
      opt2_mean = 0;

      for(int i = 0; i < iter; i++){
	r1 = gen_rand_route(nums[n]/2,widths[w]);
	r2 = gen_rand_route(nums[n]/2,widths[w]);
	rand_mean += (r1.length() + r2.length()) / iter;
	optimize_two_routes(r1,r2);
	opt2_mean += (r1.length() + r2.length()) / iter;
      }
      cout << "num: " << nums[n] << " width: " << widths[w] << endl;
      cout << "opt2 " << -(opt2_mean - rand_mean) / rand_mean << " % better than rand" << endl << endl;
    }
  }

}

void new_deliveries_simulation(){
  srand(time(NULL));
  int town_width = 150;
  int max_new = 300;
  int num_overtime = 0;
  for(int i = 0; i < 1000; i++){
    route r = gen_rand_route(800,town_width);
    randomize_delivery_days(r,5,0);
    simulate_days(r,5,town_width,max_new,num_overtime);
  }
  cout << num_overtime/ (1000*5) << endl;
}
/**
int main(){
  new_deliveries_simulation();
  return 0;
}
**/
