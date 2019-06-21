#include "calculator.hpp"
#include <cstdlib>
#include <vector>
using std::string;
using std::to_string;
using std::vector;
using namespace std::string_literals;
struct Tree {
  vector<Tree> kids;
  string value;
  Tree(string e) { value = e; }
};
int parsint(string e) {
  for (auto &x : e)
    // check if char is int
    if ('0' > x or x > '9')
      throw "NaN"s;
  return atol(e.c_str());
}
string calculator(string e) {
  try {
    return to_string(parsint(e));
  } catch (string er) {
    return er;
  }
}
