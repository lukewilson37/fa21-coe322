#include<iostream>
#include<vector>
#include<cmath> 

using std::endl;
using std::cout;
using std::vector;
using std::cin;


void goldbach(int e);

bool isprime(int n);

class primegenerator {
private:
  int number_of_primes = 0;
  int last_number_tested = 0;
public:
  int number_of_primes_found() { return number_of_primes; };
  int nextprime() {
    while( not isprime(last_number_tested + 1) ){
      last_number_tested++;
    };
    last_number_tested++;
    number_of_primes++;
    return last_number_tested;
  };
};
int main(){
  int e;
  cout << endl << "Goldbach Conjecture Test: ";
  cin >> e;
  for(int i = 4; i <= e; i += 2){
    goldbach(i);  
  }
  return 0;

}

bool isprime(int n) {
  if (n <= 1) {
    return false;
  }

  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0){
      return false;
    }
  }

  return true;
}

void goldbach(int e){
  while ( e % 2 == 1 || e < 4){
    cout << endl << "please enter even number greater than 4: ";
    cin >> e;
  }
  primegenerator testprimes;
  int p = 0;
  int q = 0;
  while(p < e && not isprime(q)){
    p = testprimes.nextprime();
    q = e-p;
    
  }
  cout << endl << "The number " << e << " is " << p << " + " << q;
}
