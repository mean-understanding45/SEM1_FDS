/*13	A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end. 
Obtain a data representation mapping a deque into a onedimensional array. 
Write C++ program to simulate deque with functions to add and delete elements from either end of the deque.*/

#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node *next, *prev;
public:
	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
	friend class Dequeue;
};

class Dequeue {
private:
	Node *front, *rear;
public:
	Dequeue() 
	{
		front = NULL, rear = NULL;
	}
	
	bool isEmpty() 
	{ return (rear == NULL && front == NULL); }
	
	int getFront() {
		if (!isEmpty()) return front->data;
		else return -1;
	}
	
	int getRear() {
		if (!isEmpty()) return rear->data;
		else return -1;
	}
	
	void insertFront(int x) 
	{
		Node *temp = new Node(x);
		if (isEmpty())
			front = rear = temp;
		else {
			temp->next = front;
			front->prev = temp;
			front = temp;
		}
	}
	
	void insertRear(int x) {
		Node* temp = new Node(x);
		if (isEmpty())
			front = rear = temp;
		else {
			temp->prev = rear;
			rear->next = temp;
			rear = temp;
		}
	}
	
	void removeFront() {
		if (isEmpty()) return;

		if (front->next == NULL) {
			delete front;
			front = rear = NULL;
		}
		else {
			Node* temp = front;
			front = front->next;
			front->prev = NULL;
			delete temp;
		}
	}
	
	void removeRear() {
		if (isEmpty()) return;

		if (front->next == NULL) {
			delete front;
			front = rear = NULL;
		}
		else {
			Node* temp = rear;
			rear = rear->prev;
			rear->next = NULL;
			delete temp;
		}
	}
	
	void Display() {
		if (isEmpty()) {
			cout << "Empty Queue\n";
			return;
		}

		Node* temp = front;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

int main() {

	Dequeue dq;

	while (true) {
		cout << "\nEnter choice --> \n1 Add to front.\n2 Add to rear.\n";
		cout << "3 Get front\n4 Get rear.\n5 Remove from front.\n6 Remove from rear.\n0 Exit.\n:";
		int choice; cin >> choice;

		if (choice == 0) break;
		else if (choice == 1) {
			cout << "Enter element to add at front: ";
			int x; cin >> x;
			dq.insertFront(x);
		}
		else if (choice == 2) {
			cout << "Enter element to add at rear: ";
			int x; cin >> x;
			dq.insertRear(x);
		}
		else if (choice == 3) {
			if (dq.isEmpty())
				cout << "Queue is empty.\n";
			else 
				cout << dq.getFront() << endl;
		}
		else if (choice == 4) {
			if (dq.isEmpty())
				cout << "Queue is empty.\n";
			else 
				cout << dq.getRear() << endl;
		}
		else if (choice == 5) {
			if (dq.isEmpty())
				cout << "Queue is empty.\n";
			else 
				dq.removeFront();
		}
		else if (choice == 6) {
			if (dq.isEmpty())
				cout << "Queue is empty.\n";
			else 
				dq.removeRear();
		}
		else cout << "INVALID CHOICE. Try Again.\n";

		cout << "Data in queue --> : ";
		dq.Display();
	}

	return 0;
}