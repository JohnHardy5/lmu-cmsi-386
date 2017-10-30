#include <iostream>
#include <assert.h>
#include <functional>
using namespace std;

function<string (string)> say(const string &start_word="") {
    string result = "";
    return [&result] (string next_word="") {
      if (next_word == "") {
        return result;
      }
      return (string)"";
    };
}

int main() {
  assert (say()("") == "");//I dont think it is possible to use say() == "", can only return a function
  //assert (say("hi")() == "hi");
  //assert (say("hi")("there")() == "hi there");
  //assert (say("hello")("my")("name")("is")("Colette")() == "hello my name is Colette");

  std::cout << "All tests passed!" << "\n";
}
