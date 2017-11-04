#include <iostream>
#include <assert.h>
#include <functional>
using namespace std;

struct Sayer {
private:
  string current_words = "";
public:
  explicit Sayer (const string& word=""): current_words(word) {}

  /*Sayer operator() (const string& next_word) {
    current_words += next_word;
    return Sayer(current_words);
  }

  string operator() () {
    return current_words;
  }*/

};

string say(const string& start_word="") {
  return "";
}

union stringOrFunction
{
  std::function<string (string, string)> f;
  string s;
};

int main() {
  assert (say() == "");
  //assert (say("hi")() == "hi");
  //assert (say("hi")("there")() == "hi there");
  //assert (say("hello")("my")("name")("is")("Colette")() == "hello my name is Colette");

  std::cout << "All tests passed!" << "\n";
}
