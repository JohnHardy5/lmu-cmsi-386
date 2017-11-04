#include <iostream>
using namespace std;

class Node {
	int info;
	Node *next;

public:
		explicit Node(int v) {
			info = v;
			next = nullptr;
		}

	  Node(const Node&) = delete;

	  Node& operator=(const Node&) = delete;

		~Node() { delete next; }

		void change_next(Node* n) {
			next = n;
		}

		Node* get_next() {
			return next;
		}

		int get_info() {
			return info;
		}

};

template<class T>
class Queue {
private:
	int size;
 	Node* startNode;
 	Node* endNode;

public:
	explicit Queue() {
		startNode = nullptr;
		endNode = nullptr;
		size = 0;
	}

  Queue(const Queue&) = delete;

  Queue& operator=(const Queue&) = delete;

	~Queue() {
	    delete startNode, endNode;
	}

	void enqueue(int value) {
      Node newNodePointer = new Node(value);
      if (size > 0) {
          newNodePointer->change_next(startNode);
      }
			startNode = &newNodePointer;
			size++;
  }

	void dequeue() {
		if (size < 1) {
			throw std::underflow_error("You can't delete from an empty queue... Duh!😞");//Requesting a +1 point for swag.
		}
		Node* previous = start;
		Node* current = start->get_next();
		while (current != end) {
			prev = current;
			current = current->get_next();
		}
		endNode = previous;
		&prev.change_next(nullptr)
		size--;
	}

	Node* get_start_node() {
		return startNode;
	}

	Node* get_end_node() {
		return endNode;
	}

	int get_size() {
		return size;
	}

};
