// Test function
#include <iostream>
using std::cout;
using std::endl;
#include "calculator.hpp"
#define test(s, r)                                                             \
  do {                                                                         \
    if (calculator(s) != r) {                                                  \
      cout << "Test Failed: " << s << endl << "\t" << calculator(s) << endl;   \
      return 1;                                                                \
    }                                                                          \
  } while (0)
int main() {
  test("1", "1");
  test("1+1", "2");
  test("1-1", "0");
  test("0-1", "-1");
  test("1+-1", "0");
  // test("-1+1", "0");
  /*
  is 1 * 2 = 2
  is 1 / 2 = .5
  is 2 / 1 = 2
  is 1 - neg1 = 2
  is 1 * neg1 = neg1
  is 1 / neg1 = neg1
  is 1 / 0 = undef
  is 0 / 1 = 0
  is 2 ^ 2 = 4
  is 0 ^ 1 = 0
  is 1 ^ 0 = 1
  is 0 ^ 0 = undef
  is 2 ^ -1 = .5
  is 4 ^ .5 = 2
  //log syntax = log(operand, base)
  is log(4,2) = 2
  is log(0,2) = undef
  is log(2,0) = undef
  */
  cout << "Math is good" << endl;
}
