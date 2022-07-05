// TESTER FILE

#include "function.h"

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

TEST_CASE( "test that f is always returns posititve" , "[1]") {

  for (int n = 0; n<1000; n++)
    REQUIRE( f(n) > 0 );

}

TEST_CASE( "test that increment_positive_only returns integers one above its input","[2]") {
  
  for (int i = 1; i<10; i++)
    REQUIRE( increment_positive_only(i) == i+1 );

}

TEST_CASE( "coefficients are polynomial","[3]") {
  auto coefficients = set_coefficients();
  REQUIRE( coefficients.size() > 0);
  REQUIRE( coefficients.front() != 0. );
}

TEST_CASE( "proper test", "[4]"){
  auto coefficients = set_coefficients();
  REQUIRE( proper_polynomial(coefficients));
  coefficients.at(0) = 0.;
  REQUIRE( not proper_polynomial(coefficients));
}

TEST_CASE( "test on polynomial evaluation","[5]") {
  vector<double> second{2,0,1};
  REQUIRE( proper_polynomial(second) );
  REQUIRE( evaluate_at(second,2) == Catch::Approx(9) );
  REQUIRE( evaluate_at(second,2) != Catch::Approx(6) );
}

TEST_CASE( "test if odd polynomial","[6]"){
  vector<double> second{2,0,1};
  REQUIRE( not is_odd(second) );
  vector<double> third{3,2,0,1};
  REQUIRE( is_odd(third) );
}

TEST_CASE( "test if good bounds","[7]"){
  double left = -1.5;
  double right = left + 1.;
  vector<double> second{2,0,1};
  REQUIRE_THROWS( find_outer(second,left,right) );
  vector<double> third{3,2,0,1};
  REQUIRE_NOTHROW( find_outer(third,left,right) );
  REQUIRE( left<right );
}

TEST_CASE( "can we find zero?","[8]"){
  double precision = 0.0001;
  double left = -5.;
  double right = 0;
  vector<double> second{2,0,1};
  REQUIRE_THROWS( find_zero(second,left,right,precision) );
  vector<double> third{3,2,0,1};
  REQUIRE_NOTHROW( find_zero(second,left,right,precision) );
  REQUIRE( find_zero(third,left,right,precision) == Catch::Approx(-1));
}
