#include <iostream>
using namespace std;

class Node {
	void *info;
	Node *next;

	public:
		Node(void *v){
			info = v;
			next = 0;
		}
		void change_next(Node *n){
			next = n;
		}
		Node *get_next(){
			return next;
		}
		void *get_info(){
			return info;
		}

};

 template<class T>
 class Queue {
 	int size = 0;
 	Node *start;
 	Node *end;
 	public:
 		Queue(T head, T tail, int size) {
 			start = new Node (&head);
 			end = new Node (&tail);
 			size = size;
 		}

 		void enqueue(T *value, int place = -1){
	        Node *temp = new Node (value);

	        if (place == 0) {
	            temp->change_next(start);
	            start = temp;
	        } else {
	        	Node *before = start;
	        	for (int i = 1; before->get_next() != 0; i++) {
	        		if (i == place) {
	        			break;
	        		}
	        		before = before->get_next();
	        	}
	        	temp->change_next(before->get_next());
	        	before->change_next(temp);
	        	size = size + 1;
	        }
	    }

    	void dequeue(int place){
    		if(size < 1){
    			throw std::underflow_error("You can't delete from an empty queue... Duh!");
    		}
    		if (place == 0) {
            	start = start->get_next();
        	} else {
            	Node *curr = start;
            	for (int i = 1; curr != 0; i ++) {
                	if (i == place) {
                    	curr->change_next(curr->get_next()->get_next());
                    	break;
                	}
                	curr = curr->get_next();
            	}
        	}
    	}

    	void get_size(){
    		cout << "size = "; size;
    	}
};