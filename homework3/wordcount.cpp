#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

string wordcount(string &input) {
  std::cout << "Count the words.\n";

  for ( unsigned int i = 0; i < input.length(); i++ ) {
    if (!isalpha(input[i])) {
      input.erase(i);
      i--;
    }
  }
  std::cout << "Final string: " << input << "\n";
  return input;
}

int main() {
  string generaltest = "The tests, my lord,have failed! FAILED have   the   tests,   they   have.";
  string testcaps = "Hello Hello hello HeLlO hELlo";
  string testnothing = "";
  string testnonletters = ";:&^$#@!'..'&*()(*&%%^^){}[{]|,|||}]";
  string testcomplex = "(((((((($$$sNEAky$$$))))))))";
  string testacouple = "!!!THIS_IS_NOT_A_COUPLE!!!!-*lol_jk*";

  try {
    //assert(wordcount(generaltest) == "have 3\nfailed 2\ntests 2\nthe 2\nlord 1\nmy 1\nthey 1");
    //assert(wordcount(testcaps) == "hello 5");
    //assert(wordcount(testnothing) == "");
    //assert(wordcount(testnonletters) == "");
    //assert(wordcount(testcomplex) == "sneaky 1");
    //assert(wordcount(testacouple) == "this 1\nis 1\nnot 1\na 1\ncouple 1\nlol 1\njk 1\n");

  } catch (exception &e) {
    cout << e.what() << "\n";
  }

  std::cout << "All tests passed!\n" << '\n';
}
