#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string removenonletters(string &input) {
  for ( int i = 0; i < (signed int)input.length(); i++ ) {
    std::cout << "Current character: " << input[i] << "   Current position: " << i << '\n';
    input[i] = tolower(input[i]);
    if (!isalpha(input[i])) {
      if (i == 0 || (i > 0 && isspace(input[i - 1]))) {
        input.replace(i, 1, "");
        i = max(0, i - 1);
      } else {
        input.replace(i, 1, " ");
      }
    }
  }
  std::cout << input << '\n';
  return input;
}

string groupsimilarwords(string &input) {
  vector<string> words;
  for ( unsigned int i = 0; i < input.length(); i++ ) {
    if (isspace(input[i])) {
      words.push_back(input.replace(0, i + 1, ""));
      std::cout << words.back() << "\n";
    }
  }
  return input;
}

string wordcount(string &input) {
  removenonletters(input);
  groupsimilarwords(input);
  std::cout << "Final string: " << input << "\n";
  return input;
}

int main() {
  string generaltest = "The tests, my lord,have failed! FAILED have   the   tests,   they   have.";
  string testcaps = " Hello Hello hello HeLlO hELlo";
  string testnothing = "";
  string testnonletters = ";:&^$#@!'..'&*()(*&%%^^){}[{]|,|||}]";
  string testcomplex = "(((((((($$$sNEAky$$$))))))))";
  string testacouple = "!!!THIS_IS_NOT_A_COUPLE!!!!-*lol_jk*";

  try {
    assert(wordcount(generaltest) == "have 3\nfailed 2\ntests 2\nthe 2\nlord 1\nmy 1\nthey 1");
    assert(wordcount(testcaps) == "hello 5");
    assert(wordcount(testnothing) == "");
    assert(wordcount(testnonletters) == "");
    assert(wordcount(testcomplex) == "sneaky 1");
    assert(wordcount(testacouple) == "this 1\nis 1\nnot 1\na 1\ncouple 1\nlol 1\njk 1\n");

  } catch (exception &e) {
    cout << e.what() << "\n";
  }

  std::cout << "All tests passed!\n" << '\n';
}
