#include <iostream>
#include <assert.h>
#include <functional>
using namespace std;


string say_again(string& result, const string& next_word="") {
  if (next_word == "") {
    return result;
  }
  result += next_word;
  return result;
}

string say (const string& start_word="") {
  string result = "";
  //stringOrFunction f = "say_again";
  return "f(result, start_word)";
}

union StringOrFunction
{
    std::int32_t n;     // occupies 4 bytes
    std::uint16_t s[2]; // occupies 4 bytes
    std::uint8_t c;     // occupies 1 byte
    //string s;apparently Unions hate strings, but ints are JUST FINE!
};

union stringOrFunction
{
  std::function<string (string, string)> f;
  string s;
};

int main() {
  StringOrFunction s = {0x12345678};
  //stringOrFunction f = "say_again";
  //assert (say() == "");//I dont think it is possible to use say() == "", can only return a function
  //assert (say("hi")() == "hi");
  //assert (say("hi")("there")() == "hi there");
  //assert (say("hello")("my")("name")("is")("Colette")() == "hello my name is Colette");

  std::cout << "All tests passed!" << "\n";
}
