#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

string remove_nonletters(const string& input) {
  string result = input;
  for (int i = 0; i < (signed int)result.length(); i++) {
    //std::cout << "Current character: " << input[i] << "   Current position: " << i << '\n';
    result[i] = tolower(result[i]);
    if (!isalpha(result[i])) {
      if (i == 0 || (i > 0 && isspace(result[i - 1]))) {
        result.replace(i, 1, "");
        i = (i == 0) ? -1 : i - 1;
      } else {
        result.replace(i, 1, " ");
      }
    }
  }
  if (result.length() > 0 && !isspace(result[result.length() - 1])) {
    result.append(" ");
  }
  //std::cout << "Non-letters removed: " << result << '\n';
  return result;
}

vector<string> group_words_in_vector(const string& input) {
  //cout << "Input: " << input << '\n';
  vector<string> result;
  int pivot = 0;
  for (unsigned int i = 0; i < input.length(); i++) {
    if (isspace(input[i]) || i == input.length() - 1) {
      //std::cout << "Replacing input: " << input.substr(pivot, i - pivot + 1) << '\n';
      result.push_back(input.substr(pivot, i - pivot + 1));
      pivot = i + 1;
    }
  }
  return result;
}

vector<string> group_similar_words(const vector<string>& words, vector<int>& wordscount) {
  vector<string> result = words;
  for (int i = result.size() - 1; i >= 0; i--) {
    wordscount.insert(wordscount.begin(), 1);
    //std::cout << "New word count added." << '\n';
    //std::cout << "Current word: " << words[i] << '\n';
    for (int j = i - 1; j >= 0; j--) {
      if (result[i] == result[j]) {
        //std::cout << "Found match: " << words[i] << "and " << words[j] << '\n';
        //std::cout << "Adding to the front of word count." << '\n';
        wordscount.front()++;
        //std::cout << "Erasing position: " << to_string(j) << '\n';
        //std::cout << "Before erase: " << words[j + 1] << ", " << words[j] << ", " << words[j - 1] << '\n';
        result.erase(result.begin() + j);
        //std::cout << "After erase: " << words[j + 1] << ", " << words[j] << ", " << words[j - 1] << '\n';
        i--;
      }
    }
    result[i] = result[i] + to_string(wordscount.front()) + "\n";
    //std::cout << "Grouping similar words: " << result[i];
  }
  return result;
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
    //std::cout << "Swapping words: " << words[i] << "and " << words[largestPosition];
    string tempStr = words[i];
    words[i] = words[largestPosition];
    //std::cout << words[i];
    words[largestPosition] = tempStr;
    int tempInt = wordscount[i];
    wordscount[i] = wordscount[largestPosition];
    wordscount[largestPosition] = tempInt;
    //std::cout << "Swapped words: " << words[i] << "and " << words[largestPosition];
  }
  return words;
}

string convert_vector_to_string(const vector<string> &words) {
  string result = "";
  for (string const& word : words) { result += word; }
  return result;
}

string wordcount(const string &input) {
  string result = input;
  result = remove_nonletters(result);
  vector<string> words = group_words_in_vector(result);
  vector<int> wordscount;
  words = group_similar_words(words, wordscount);
  words = sort_words_large_to_small(words, wordscount);
  result = convert_vector_to_string(words);
  //std::cout << "Final string: " << result << "\n";
  return result;
}

int main() {
  string general_test = "The tests, my lord,have failed! FAILED have   the   tests,   they   have.";
  string test_caps = "   Hello Hello hello HeLlO hELlo   ";
  string test_letter = "G";
  string test_word = "GiT";
  string test_nothing = "";
  string test_space = " ";
  string test_spaces = "   ";
  string test_nonletters = ";:&^$#@!'. .'&*()(*&%%^^){}[{]|,|||}]";
  string test_complex = "(((((((($$$sNEAky$$$))))))))";
  string test_a_couple = "!!!THIS_IS_NOT_A_COUPLE!!!!-*lol_jk*";
  string test_emojis = "😄🍰😞yay!emojis!🐷👩";
  string test_weird = "в聲字вwtfЖ_ЛareЙ_字яtheseЮ_пфthings形?";

  try {
    assert(wordcount(general_test) == "have 3\nfailed 2\nthe 2\ntests 2\nlord 1\nthey 1\nmy 1\n");
    assert(wordcount(test_caps) == "hello 5\n");
    assert(wordcount(test_letter) == "g 1\n");
    assert(wordcount(test_word) == "git 1\n");
    assert(wordcount(test_nothing) == "");
    assert(wordcount(test_space) == "");
    assert(wordcount(test_spaces) == "");
    assert(wordcount(test_nonletters) == "");
    assert(wordcount(test_complex) == "sneaky 1\n");
    assert(wordcount(test_a_couple) == "this 1\nis 1\nnot 1\na 1\ncouple 1\nlol 1\njk 1\n");
    assert(wordcount(test_emojis) == "yay 1\nemojis 1\n");
    assert(wordcount(test_weird) == "wtf 1\nare 1\nthese 1\nthings 1\n");
  } catch (exception &e) {
    cout << e.what() << "\n";
  }
  std::cout << "All tests passed!\n";
}
