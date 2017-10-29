#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void remove_nonletters(string &input) {
  for (unsigned int i = 0; i < input.length(); i++) {
    //std::cout << "Current character: " << input[i] << "   Current position: " << i << '\n';
    input[i] = tolower(input[i]);
    if (!isalpha(input[i])) {
      if (i == 0 || (i > 0 && isspace(input[i - 1]))) {
        input.replace(i, 1, "");
        i = (i == 0) ? 0 : i - 1;
      } else {
        input.replace(i, 1, " ");
      }
    }
  }
  std::cout << "Non-letters removed: " << input << '\n';
}

vector<string> group_words_in_vector(string &input) {
  vector<string> words;
  int pivot = 0;
  for (unsigned int i = 0; i < input.length(); i++) {
    if (isspace(input[i])) {
      //std::cout << "Replacing input: " << input.substr(pivot, i - pivot + 1) << '\n';
      words.push_back(input.substr(pivot, i - pivot + 1));
      pivot = i + 1;
    }
  }
  return words;
}

vector<string> sort_words_large_to_small(vector<string> &words, vector<int> &wordscount) {
  //std::cout << "First word: " << words[0];
  for (unsigned int i = 0; i < wordscount.size(); i++) {
    //std::cout << "Comparing word: " << words[i];
    int largest = 1;
    int largestPosition = i;
    for (unsigned int j = i + 1; j < wordscount.size(); j++) {
      //std::cout << "with word: " << words[j];
      if (wordscount[j] > largest) {
        //std::cout << "Found larger value: " << wordscount[j] << " than: " << to_string(largest) << '\n';
        largest = wordscount[j];
        largestPosition = j;
      }
    }
    std::cout << "Swapping words: " << words[i] << "and " << words[largestPosition];
    string tempStr = words[i];
    words[i] = words[largestPosition];
    std::cout << words[i];
    words[largestPosition] = tempStr;
    int tempInt = wordscount[i];
    wordscount[i] = wordscount[largestPosition];
    wordscount[largestPosition] = tempInt;
    //std::cout << "Swapped words: " << words[i] << "and " << words[largestPosition];
  }
  //std::cout << "First word: " << words[0];
  return words;
}

string convert_vector_to_string(vector<string> &words) {
  //std::cout << "First word: " << words[0];
  string result = "";
  for (string const& word : words) { result += word; }
  return result;
}

void group_similar_words(string &input) {
  vector<string> words = group_words_in_vector(input);
  vector<int> wordscount;
  for (int i = words.size() - 1; i >= 0; i--) {
    wordscount.insert(wordscount.begin(), 1);
    //std::cout << "New word count added." << '\n';
    //std::cout << "Current word: " << words[i] << '\n';
    for (int j = i - 1; j >= 0; j--) {
      if (words[i] == words[j]) {
        //std::cout << "Found match: " << words[i] << "and " << words[j] << '\n';
        //std::cout << "Adding to the front of word count." << '\n';
        wordscount.front()++;
        //std::cout << "Erasing position: " << to_string(j) << '\n';
        //std::cout << "Before erase: " << words[j + 1] << ", " << words[j] << ", " << words[j - 1] << '\n';
        words.erase(words.begin() + j);
        //std::cout << "After erase: " << words[j + 1] << ", " << words[j] << ", " << words[j - 1] << '\n';
        i--;
      }
    }
    words[i] = words[i] + to_string(wordscount.front()) + "\n";
    std::cout << "Grouping similar words: " << words[i];
  }
  //std::cout << "First word: " << words[0];
  words = sort_words_large_to_small(words, wordscount);
  //std::cout << "First word: " << words[0];
  input = convert_vector_to_string(words);
}

string wordcount(string &input) {
  remove_nonletters(input);
  group_similar_words(input);
  std::cout << "Final string: " << input << "\n";
  return input;
}

int main() {
  string generaltest = "The tests, my lord,have failed! FAILED have   the   tests,   they   have.";
  string testcaps = "  Hello Hello hello HeLlO hELlo   ";
  string testnothing = "";
  string testnonletters = ";:&^$#@!'. .'&*()(*&%%^^){}[{]|,|||}]";
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
