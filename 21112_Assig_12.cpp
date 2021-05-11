/*Write program to implement a priority queue in C++ using an inorder list to store the items in the queue. 
Create a class that includes the data items (which should be template) and 
the priority (which should be int). The inorder list should contain these objects, 
with operator <= overloaded so that the items with highest priority appear at the 
beginning of the list (which will make it relatively easy to retrieve the highest item.) */

#include <iostream>
using namespace std;

const int D = 6;

class Item
{
private:
	string Iname;
	int priority;

public:
	Item(string Iname = "", int priority = 0)
	{
		this->Iname = Iname;
		this->priority = priority;
	}
	void Read()
	{
		cout << "Enter item name : " << endl;
		cin >> Iname;
		cout << "Enter Priority : " << endl;
		cin >> priority;
	}
	string getName()
	{
		return Iname;
	}
	int getPriority()
	{
		return priority;
	}
	friend bool operator<=(Item, Item);
	friend ostream &operator<<(ostream &Itemout, Item i);
};

bool operator<=(Item i1, Item i2)
{
	return (i1.priority <= i2.priority);
}

ostream &operator<<(ostream &Itemout, Item i)
{
	Itemout << "Item: " << i.Iname << " Priority: " << i.priority << endl;
	return Itemout;
}

// priority queue implementation
template <class T>
class PriorityQueue
{
private:
	T arr[D];
	int n;

public:
	PriorityQueue()
	{
		n = 0;
	}
	int getSize()
	{
		return n;
	}
	bool isEmpty()
	{
		return (n < 1);
	}
	bool isFull()
	{
		return (n == D);
	}
	T front()
	{
		return arr[0];
	}
	void enqueue(T x)
	{
		if (isFull())
			return;
		arr[n] = x;
		n++;
		//shift the current element at appropriate position
		for (int i = n - 1; i >= 1; i--)
			if (arr[i - 1] <= arr[i])
				swap(arr[i], arr[i - 1]);
	}
	void dequeue()
	{
		if (isEmpty())
			return;
		// shift elements by one
		cout << "Removed item :--> " << arr[0] << endl;
		for (int i = 0; i < n - 1; i++)
			arr[i] = arr[i + 1];
		n--;
	}
	void display()
	{
		if (isEmpty())
			cout << "Empty List.\n";

		for (int i = 0; i < n; i++)
			cout << arr[i];
		cout << endl;
	}
};

int main()
{
	PriorityQueue<Item> pq;

	while (true)
	{
		cout << "\n1 To add Item.\n2 To print topmost Item.\n3 To remove Item.\n";
		cout << "4 To print queue\n0 To exit.\nEnter choice :--> : ";
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			if (pq.isFull())
				cout << "Queue is full.\n";
			else
			{
				Item temp;
				temp.Read();
				pq.enqueue(temp);
				cout << "Item added Successfully\n";
			}
		}
		else if (choice == 2)
		{
			if (pq.isEmpty())
				cout << "Queue is empty.\n";
			else
				cout << pq.front();
		}
		else if (choice == 3)
		{
			if (pq.isEmpty())
				cout << "Queue is empty.\n";
			else
			{
				pq.dequeue();
				cout << "Item removed Successfully.\n";
			}
		}
		else if (choice == 4)
		{
			cout << "Data in queue is:-->\n";
			pq.display();
		}
		else if (choice == 0)
			break;
		else
			cout << "INVALID CHOICE\n";
	}

	return 0;
}