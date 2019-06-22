#include "calculator.hpp"
#include <cstdlib>
#include <vector>
using std::string;
using std::to_string;
using std::vector;
using namespace std::string_literals;
bool isanumber(char c) { return '0' <= c && c <= '9'; }
string calculator(string e) {
  // trash spaces
  for (int index = 0; index < e.size(); index++)
    if (e[index] == ' ')
      e.erase(index, 1);
  // look through string for (, if found, eval substring between ( and )
  for (int index = 0; index < e.size(); index++) {
    if (e[index] == '(') {
      // find ) then calculator(substring)
      int depth = 0;
      for (int index2 = index; index2 < e.size(); index2++) {
        if (e[index] == '(')
          depth++;
        if (e[index] == ')')
          if (depth == 0)
            // remove substring between index and index2, call calculator with
            // substring, replace with return of calculator
            return calculator(
                e.replace(index, index2 - index,
                          calculator(e.substr(index + 1, index2 - index - 2))));

          else
            depth--;
      }
    }
  }
  // no more para yay
  // adding for loop, find + then takes index-nonnum and index +nonnum and
  // replaces that substring with index -nonum + index+nonnum
  for (int index = 0; index < e.size(); index++) {
    if (e[index] == '+') {
      int left, right;
      for (left = index - 1; left >= 0 && isanumber(e[left]); left--)
        ;
      for (right = index + 1; right < e.size() && isanumber(e[right]); right++)
        ;
      if (!isanumber(e[left]))
        left++;
      if (!isanumber(e[right]))
        right--;
      e.replace(left, right - left + 1,
                to_string(atol(e.substr(left, index - left).c_str()) +
                          atol(e.substr(index + 1, right - index).c_str())));
    }
    if (e[index] == '-') {
      int left, right;
      for (left = index - 1; left >= 0 && isanumber(e[left]); left--)
        ;
      for (right = index + 1; right < e.size() && isanumber(e[right]); right++)
        ;
      if (!isanumber(e[left]))
        left++;
      if (!isanumber(e[right]))
        right--;
      e.replace(left, right - left + 1,
                to_string(atol(e.substr(left, index - left).c_str()) -

                          atol(e.substr(index + 1, right - index).c_str())));
    }
  }
  return e;
}
// 1+3*5(4-2) see ( and do between ( and ) first, then if int directly next to
// it, insert * between them, then do */ and then do +-
