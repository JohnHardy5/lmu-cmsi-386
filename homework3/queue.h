#include <iostream>
using namespace std;

template<typename T>
class Node {
private:
	T data;
	Node* next;

public:
		explicit Node(const T& d): data(d), next(nullptr) {}

	  Node(const Node&) = delete;

	  Node& operator= (const Node&) = delete;

		~Node() { delete next; }

		void change_next(Node* n) {
			next = n;
		}

		Node* get_next() {
			return next;
		}

		T get_data() {
			return data;
		}

};

template<typename T>
class Queue {
private:
 	Node<T>* startNode;
 	Node<T>* endNode;
	int size;

public:
	explicit Queue(): startNode(nullptr), endNode(nullptr), size(0) {}

  Queue(const Queue&) = delete;

  Queue& operator= (const Queue&) = delete;

	~Queue() {
	    delete startNode;
			delete endNode;
	}

	void enqueue(const T& value) {
      Node<T>* newNodePointer = new Node<T>(value);
      if (size > 0) {
          newNodePointer->change_next(startNode);
      }
			startNode = newNodePointer;
			size++;
			delete newNodePointer;
  }

	void dequeue() {
		if (size < 1) {
			throw std::underflow_error("You can't delete from an empty queue... Duh!😞");
		}
		Node<T>* previous = startNode;
		Node<T>* current = startNode->get_next();
		while (current != endNode) {
			previous = current;
			current = current->get_next();
		}
		endNode = previous;
		previous.change_next(nullptr);
		size--;
	}

	Node<T>* get_start_node() {
		return startNode;
	}

	Node<T>* get_end_node() {
		return endNode;
	}

	int get_size() {
		return size;
	}

};
