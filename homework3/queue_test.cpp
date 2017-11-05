#include "queue.h"
#include <assert.h>
#include <iostream>
using namespace std;

void testEnqueue() {
  Queue<string> test;

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);
  std::cout << "Enqueue with empty queue tests passed." << '\n';

  test.enqueue("Why ");

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == "Why ");
  assert(test.get_end_node()->get_data() == "Why ");
  std::cout << "Enqueue with one item tests passed." << '\n';

  test.enqueue("is ");
  test.enqueue("this ");
  test.enqueue("so ");
  test.enqueue("hard?");

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 5);
  assert(test.get_start_node()->get_data() == "Why ");
  assert(test.get_end_node()->get_data() == "hard?");
  std::cout << "Enqueue with multiple items tests passed." << '\n';
}

void testDequeue() {
  Queue<string> test;

  test.enqueue("Why ");
  test.enqueue("is ");
  test.enqueue("this ");
  test.enqueue("so ");
  test.enqueue("hard?");

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 5);
  assert(test.get_start_node()->get_data() == "Why ");
  assert(test.get_end_node()->get_data() == "hard?");
  std::cout << "Dequeue with multiple items tests passed." << '\n';

  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 4);
  assert(test.get_start_node()->get_data() == "is ");
  assert(test.get_end_node()->get_data() == "hard?");
  std::cout << "Dequeue with one less item tests passed." << '\n';

  test.dequeue();
  test.dequeue();
  test.dequeue();

  assert(test.get_end_node() != nullptr);
  assert(test.get_start_node() != nullptr);
  assert(test.get_size() == 1);
  assert(test.get_start_node()->get_data() == "hard?");
  assert(test.get_end_node()->get_data() == "hard?");
  std::cout << "Dequeue with one last item tests passed." << '\n';

  test.dequeue();

  assert(test.get_end_node() == nullptr);
  assert(test.get_start_node() == nullptr);
  assert(test.get_size() == 0);
  std::cout << "Dequeue with no items tests passed." << '\n';
}

int main() {
  testEnqueue();
  testDequeue();

  std::cout << "All tests passed!" << '\n';
}
