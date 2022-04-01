// implementation of circular queue data structure using arrays

#include <iostream>

using namespace std;

class CircularQueue{
private:
	int front;	// front end
	int rear;	// rear end
	int arr[5];
	int itemCount;

public:
	CircularQueue()
	{
		itemCount = 0;

		// queue is empty when rear and front are -1
		front = -1;
		rear = -1;
		// filling array with zeros
		for(int i = 0; i < 5; i++)
		{
			arr[i] = 0;
		}
	}

	bool isEmpty()
	{
		if(front == -1 && rear == -1)
			return true;
		else 
			return false;
	}

	bool isFull()
	{
		if ((rear+1)%5 == front)
			return true;
		else
			return false;
	}

	void enqueue(int val)	// elements added at rear end
	{
		if(isFull())
		{
			cout<<"Queue is FULL"<<endl;
			return;
		}
		else if(isEmpty())
		{
			// when only single element in queue, rear and front are same
			rear = 0;
			front = 0;
			arr[rear] = val;
		}
		else
		{
			rear = (rear+1)%5;	// the queue will iterate only between 0 and size of array 
			arr[rear] = val;
		}
		itemCount++;
	}

	int dequeue()	// elements are remoevd from front end
	{
		if(isEmpty())
		{
			cout<<"Queue is EMPTY"<<endl;
			return 0;
		}
		else if(front == rear)		// only a single value in queue
		{
			int x = arr[front];
			arr[front] = 0;

			// queue becomes empty so update rear and front
			rear = -1;
			front = -1;
			itemCount--;
			return x;
		}
		else
		{
			int x = arr[front];
			arr[front] = 0;
			front = (front + 1)%5;	// iterate values over 0 to size of array 
			itemCount--;
			return x;
		}
	}

	int count()
	{
		return itemCount;
	}

	void display()
	{
		cout<<"All values in the Queue are: "<<endl;
		for(int i = 0; i < 5; i++)
		{
			cout<<arr[i]<<" ";
		}
	}
};

int main()
{
	CircularQueue q1;
	int option, value;

	do
	{
		cout<<"\nSelect operation no. Enter 0 to exit"<<endl;
		cout<<"1. Enqueue()"<<endl;
		cout<<"2. Dequeue()"<<endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. isFull()"<<endl;
		cout<<"5. count()"<<endl;
		cout<<"6. display()"<<endl;
		cout<<"7. Clear Screen"<<endl;

		cin>>option;
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Enter value to enqueue into queue: "<<endl;
				cin>>value;
				q1.enqueue(value);
				break;
			case 2:
				cout<<"Deueued value: "<<q1.dequeue()<<endl;
				break;
			case 3:
				if(q1.isEmpty())
					cout<<"Queue is Empty";
				else
					cout<<"Queue is not Empty";
				break;
			case 4:
				if(q1.isFull())
					cout<<"Queue is Full";
				else
					cout<<"Queue is not Full";
				break;
			case 5:
				cout<<"Count function called. Count of Elements in the queue is: "<<q1.count()<<endl;
				break;
			case 6:
				cout<<"Display function called - "<<endl;
				q1.display();
				break;
			case 7:
				system("clear");	//clear screen
				break;
			default:
				cout<<"Enter a valid option number";
		}

	}while(option != 0);

	return 0;
}