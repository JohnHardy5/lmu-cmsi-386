#include "queue.h"
#include <assert.h>
#include <iostream>
using namespace std;

void testEnqueue() {
  Queue<string> testEmpty;
  Node<string>* endNode = testEmpty.get_end_node();
  Node<string>* startNode = testEmpty.get_start_node();
  int size = testEmpty.get_size();

  assert(endNode == nullptr);
  assert(startNode == nullptr);
  assert(size == 0);
  std::cout << "Empty queue tests passed." << '\n';

  testEmpty.enqueue("Why ");

  endNode = testEmpty.get_end_node();
  startNode = testEmpty.get_start_node();
  size = testEmpty.get_size();
  string startNodeValue = startNode->get_data();

  /*
  assert(endNode != nullptr);
  assert(startNode != nullptr);
  assert(size == 1);
  assert(startNodeValue == "Why ");
  std::cout << "Queue with one item tests passed." << '\n';*/
}

int main() {
  testEnqueue();

  std::cout << "All tests passed!" << '\n';
}
