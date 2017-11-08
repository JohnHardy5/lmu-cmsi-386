/*
   "It is better to feel good than to feel bad." --Dr. Ray Toal November 2017
   Written by: John Hardy and Jordan Sanders
*/

#include <iostream>
#include <cassert>

using namespace std;


template<typename T>
class Node {
	T data;
	Node* next;

public:
	explicit Node(const T& d): data(d), next(nullptr) {}

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
public:
 	Node<T>* startNode;
 	Node<T>* endNode;
	int size;

	explicit Queue(): startNode(nullptr), endNode(nullptr), size(0) {}

    Queue(const Queue& q) = delete;

    Queue& operator= (const Queue&) = delete;

	~Queue() {
		delete startNode;
		delete endNode;
	}

	void enqueue(const T& value) {
	    //cout << "starting enqueue" << endl;
			Node<T>* newNodePointer = new Node<T>(value);
	    //cout << "made a node" << endl;
      if (size > 0) {
  	    //cout << "okay bigger than zero, updating end node's next field" << endl;
				endNode->change_next(newNodePointer);
      } else {
  	    //cout << "it's empty so new tail is the new head" << endl;
				startNode = newNodePointer;
			}
      //cout << "queue points to new tail" << endl;
			endNode = newNodePointer;
      //cout << "all set" << endl;
			size++;
      //cout << "size is now " << size << endl;
		}

	void dequeue() {
		if (size < 1) {
			throw std::underflow_error("You can't delete from an empty queue... Duh!😞");
		}

		Node<T>* nodeToDelete = startNode;

		// Move startNode to the new head (this will be nullptr if there's only one node)
		//std::cout << "Setting startNode to next value" << '\n';
		startNode = startNode->get_next();
		nodeToDelete->change_next(nullptr);
        // if the start node was the end node, gotta make that nullptr too
		if (size == 1) {
			//std::cout << "Setting endnode to nullptr" << '\n';
			endNode = nullptr;
		}
		//std::cout << "decrementing size" << '\n';
		size--;
		//std::cout << "done!" << '\n';
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
