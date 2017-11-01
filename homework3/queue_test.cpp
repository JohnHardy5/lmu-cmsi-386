#include "queue.h"

void testEnqueue() {
  Queue<T> testEmpty = new Queue()
  assert(testEmpty.get_end_node() == nullptr);
  assert(testEmpty.get_start_node() == nullptr);

}

int main() {
    int nine = 9;
    int eight = 8;
    int seven = 7;
    int six = 6;
    int five = 5;

    cout << "Create queue holding 9 and 8 with a size of 2" << "\n";
    Queue<T> test_queue = new Queue(&nine,&eight,2);
}
