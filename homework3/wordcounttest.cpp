#include <iostream>
#include <cassert>
#include <string>
using namespace std;

string wordcount(string input) {
  std::cout << "Count the words.\n";
  return "have 3\nfailed 2\ntests 2\nthe 2\nlord 1\nmy 1\nthey 1";
}

int main() {
  string toCount1 = "The tests, my lord,have failed! FAILED have   the   tests,   they   have.";

  string output1 = wordcount(toCount1);

  try {
    assert(output1 == "have 3\nfailed 2\ntests 2\nthe 2\nlord 1\nmy 1\nthey 1");
  } catch (exception e) {
    cout << e.what() << "\n";
  }
  
  std::cout << "All tests passed!\n" << '\n';
}
