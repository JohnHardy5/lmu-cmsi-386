#include <iostream>
#include <cassert>

using namespace std;


template<typename T>
class Node {
private:
	T data;
	Node* next;

public:
	explicit Node(const T& d): data(d), next(nullptr) {}

	~Node() { delete next; }

	Node* get_next() {
		return next;
	}

	void change_next(Node* n) {
		next = n;
	}

	T get_data() {
		return data;
	}
};

template<typename T>
class Queue {
public:
	Node<T>* startNode;
	Node<T>* endNode;
	int size;

	explicit Queue(): startNode(nullptr), endNode(nullptr), size(0) {}

	Queue(const Queue&) = delete;

	Queue& operator=(const Queue&) = delete;

	~Queue() {
		delete startNode;
	}

	void enqueue(const T& value) {
		Node<T>* newNodePointer = new Node<T>(value);
		if (size > 0) {
			endNode->change_next(newNodePointer);
		} else {
			startNode = newNodePointer;
		}
		endNode = newNodePointer;
		size++;
	}

	void dequeue() {
		if (size < 1) {
			throw std::underflow_error("You can't delete from an empty queue... Duh!😞");
		}

		Node<T>* nodeToDelete = startNode;

		startNode = startNode->get_next();
		nodeToDelete->change_next(nullptr);
		if (size == 1) {
			endNode = nullptr;
		}
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
