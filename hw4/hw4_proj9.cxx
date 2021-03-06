#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#include<cmath>
using std::sqrt;

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
 

/* int main(){
  int nprimes = 0;
  cin >> nprimes;
  primegenerator sequence;
  while(sequence.number_of_primes_found() < nprimes){
    int number = sequence.nextprime();
    cout << "Number " << number << " is prime" << endl;
  }
 return  0;
}
*/

bool isprime(int n) {
  if (n<=1) {
    return false;
  }

  for(int i = 2; i <= sqrt(n); i++) {
    if(n % i == 0){
      return false;
    }
  }

    return true;
}

