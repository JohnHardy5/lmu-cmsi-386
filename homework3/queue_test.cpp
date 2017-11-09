/*
   "It is better to feel good than to feel bad." --Dr. Ray Toal November 2017
   Written by: John Hardy and Jordan Sanders
*/

#include "queue.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <array>
using namespace std;

void testString() {
  Queue<string> test;

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);

  test.enqueue("Why ");

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == "Why ");
  assert(test.get_end_node()->get_data() == "Why ");

  test.enqueue("is ");
  test.enqueue("this ");
  test.enqueue("so ");
  test.enqueue("hard?");

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 5);
  assert(test.get_start_node()->get_data() == "Why ");
  assert(test.get_end_node()->get_data() == "hard?");

  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 4);
  assert(test.get_start_node()->get_data() == "is ");
  assert(test.get_end_node()->get_data() == "hard?");

  test.dequeue();
  test.dequeue();
  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == "hard?");
  assert(test.get_end_node()->get_data() == "hard?");

  test.dequeue();

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);

  try {
    test.dequeue();
    assert(false);
  } catch (const underflow_error& ue) {
    assert(true);
  } catch (...) {
    std::cout << "Does not throw an error when I dequeue from an empty string Queue." << '\n';
    assert(false);
  }
}

void testInt() {
  Queue<int> test;

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);

  test.enqueue(1);

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == 1);
  assert(test.get_end_node()->get_data() == 1);

  test.enqueue(2);
  test.enqueue(3);
  test.enqueue(4);
  test.enqueue(5);

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 5);
  assert(test.get_start_node()->get_data() == 1);

  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 4);
  assert(test.get_start_node()->get_data() == 2);
  assert(test.get_end_node()->get_data() == 5);

  test.dequeue();
  test.dequeue();
  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == 5);
  assert(test.get_end_node()->get_data() == 5);

  test.dequeue();

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);

  try {
    test.dequeue();
    assert(false);
  } catch (const underflow_error& ue) {
    assert(true);
  } catch (...) {
    std::cout << "Does not throw an error when I dequeue from an empty int Queue." << '\n';
    assert(false);
  }
}

void testVector() {
  Queue<vector<bool>> test;

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);

  test.enqueue({true});

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == vector<bool>{true});
  assert(test.get_end_node()->get_data() == vector<bool>{true});

  test.enqueue({});
  test.enqueue({true});
  test.enqueue({false, true});
  test.enqueue({false, false});

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 5);
  assert(test.get_start_node()->get_data() == vector<bool>{true});
  assert(test.get_end_node()->get_data() == (vector<bool>{false, false}));

  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 4);
  assert(test.get_start_node()->get_data() == vector<bool>{});
  assert(test.get_end_node()->get_data() == (vector<bool>{false, false}));

  test.dequeue();
  test.dequeue();
  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == (vector<bool>{false, false}));
  assert(test.get_end_node()->get_data() == (vector<bool>{false, false}));

  test.dequeue();

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);

  try {
    test.dequeue();
    assert(false);
  } catch (const underflow_error& ue) {
    assert(true);
  } catch (...) {
    std::cout << "Does not throw an error when I dequeue from an empty vector Queue." << '\n';
    assert(false);
  }
}

void testArray() {
  Queue<array<int, 1>> test;

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);

  test.enqueue({1});

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == (array<int, 1>{1}));
  assert(test.get_end_node()->get_data() == (array<int, 1>{1}));

  test.enqueue({});
  test.enqueue({3});
  test.enqueue({4});
  test.enqueue({5});

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 5);
  assert(test.get_start_node()->get_data() == (array<int, 1>{1}));
  assert(test.get_end_node()->get_data() == (array<int, 1>{5}));

  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 4);
  assert(test.get_start_node()->get_data() == (array<int, 1>{}));
  assert(test.get_end_node()->get_data() == (array<int, 1>{5}));

  test.dequeue();
  test.dequeue();
  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == (array<int, 1>{5}));
  assert(test.get_end_node()->get_data() == (array<int, 1>{5}));

  test.dequeue();

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);

  try {
    test.dequeue();
    assert(false);
  } catch (const underflow_error& ue) {
    assert(true);
  } catch (...) {
    std::cout << "Does not throw an error when I dequeue from an empty array Queue." << '\n';
    assert(false);
  }
}

int main() {
  testString();
  testInt();
  testVector();
  testArray();

  std::cout << "All tests passed!" << '\n';
}
