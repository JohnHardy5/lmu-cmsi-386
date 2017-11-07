#include "queue.h"
#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

void testString() {
  Queue<string> test;

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);
  std::cout << "String enqueue with empty queue tests passed." << '\n';

  test.enqueue("Why ");

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == "Why ");
  assert(test.get_end_node()->get_data() == "Why ");
  std::cout << "String enqueue with one item tests passed." << '\n';

  test.enqueue("is ");
  test.enqueue("this ");
  test.enqueue("so ");
  test.enqueue("hard?");

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 5);
  assert(test.get_start_node()->get_data() == "Why ");
  assert(test.get_end_node()->get_data() == "hard?");
  std::cout << "String enqueue with multiple items tests passed." << '\n';

  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 4);
  assert(test.get_start_node()->get_data() == "is ");
  assert(test.get_end_node()->get_data() == "hard?");
  std::cout << "String dequeue with one less item tests passed." << '\n';

  test.dequeue();
  test.dequeue();
  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == "hard?");
  assert(test.get_end_node()->get_data() == "hard?");
  std::cout << "String dequeue with one last item tests passed." << '\n';

  test.dequeue();

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);
  std::cout << "String dequeue with no items tests passed." << '\n';

  try {
    test.dequeue();
  } catch (exception& e) {
    std::cout << "Successfully throws an error when I dequeue from an empty string Queue." << '\n';
  }
}

void testInt() {
  Queue<int> test;

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);
  std::cout << "Int enqueue with empty queue tests passed." << '\n';

  test.enqueue(1);

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == 1);
  assert(test.get_end_node()->get_data() == 1);
  std::cout << "Int enqueue with one item tests passed." << '\n';

  test.enqueue(2);
  test.enqueue(3);
  test.enqueue(4);
  test.enqueue(5);

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 5);
  assert(test.get_start_node()->get_data() == 1);
  assert(test.get_end_node()->get_data() == 5);
  std::cout << "Int enqueue with multiple items tests passed." << '\n';

  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 4);
  assert(test.get_start_node()->get_data() == 2);
  assert(test.get_end_node()->get_data() == 5);
  std::cout << "Int dequeue with one less item tests passed." << '\n';

  test.dequeue();
  test.dequeue();
  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == 5);
  assert(test.get_end_node()->get_data() == 5);
  std::cout << "Int dequeue with one last item tests passed." << '\n';

  test.dequeue();

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);
  std::cout << "Int dequeue with no items tests passed." << '\n';

  try {
    test.dequeue();
  } catch (exception& e) {
    std::cout << "Successfully throws an error when I dequeue from an empty int Queue." << '\n';
  }
}

void testVector() {
  Queue<vector<bool>> test;

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);
  std::cout << "Vector enqueue with empty queue tests passed." << '\n';

  test.enqueue({true});

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == vector<bool>{true});
  assert(test.get_end_node()->get_data() == vector<bool>{true});
  std::cout << "Vector enqueue with one item tests passed." << '\n';

  test.enqueue({});
  test.enqueue({true});
  test.enqueue({false, true});
  test.enqueue({false, false});

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 5);
  assert(test.get_start_node()->get_data() == vector<bool>{true});
  assert(test.get_end_node()->get_data() == (vector<bool>{false, false}));
  std::cout << "Vector enqueue with multiple items tests passed." << '\n';

  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 4);
  assert(test.get_start_node()->get_data() == vector<bool>{});
  assert(test.get_end_node()->get_data() == (vector<bool>{false, false}));
  std::cout << "Vector dequeue with one less item tests passed." << '\n';

  test.dequeue();
  test.dequeue();
  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == (vector<bool>{false, false}));
  assert(test.get_end_node()->get_data() == (vector<bool>{false, false}));
  std::cout << "Vector dequeue with one last item tests passed." << '\n';

  test.dequeue();

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);
  std::cout << "Vector dequeue with no items tests passed." << '\n';

  try {
    test.dequeue();
  } catch (exception& e) {
    std::cout << "Successfully throws an error when I dequeue from an empty vector Queue." << '\n';
  }
}

int main() {
  testString();
  testInt();
  testVector();

  std::cout << "All tests passed!" << '\n';
}
