// implementation of a stack dtaa structure
#include <iostream>
#include <string>

using namespace std;

class Stack{
	private:
		int top;
		int arr[5];

	public:
		Stack()
		{
			top = -1;
			for(int i = 0; i < 5; i++)
			{
				arr[i] = 0;
			}
		}

		bool isEmpty()	// check if stack is empty
		{
			if(top == -1)
				return true;
			else
				return false;
		}

		bool isFull()	// check if stack is full
		{
			if(top == 4)
				return true;
			else
				return false;
		}

		void push(int val)
		{
			if(isFull())
				cout<<"stack overflow"<<endl;
			else
			{
				top++;
				arr[top] = val;
			}
		}

		int pop()
		{
			if(isEmpty())		// stack underflow
			{
				cout<<"stack underflow"<<endl;
				return 0;
			}	

			else
			{
				int popValue = arr[top];
				arr[top] = 0;
				top--;
				return popValue;
			}
		}

		int count()		// count no. of values in stack
		{
			return top + 1;
		}

		int peek(int pos)	// return value at nth position
		{
			if(isEmpty())		// stack underflow
			{
				cout<<"stack underflow"<<endl;
				return 0;
			}
			else
			{
				return arr[pos];
			}
		}

		void change(int pos, int val)	// change value at nth position
		{
			arr[pos] = val;
			cout<<"value changed at location "<<pos<<endl;
		}

		void display()		// display all elements in stack
		{
			cout<<"All values in the stack are "<<endl;
			for(int i = 4; i >= 0; i--)
			{
				cout<<arr[i]<<endl;
			}
		}
};


int main()
{
	Stack s1;
	int option, position, value;
	do
	{
		cout<<"\nSelect operation no. Enter 0 to exit"<<endl;
		cout<<"1. Push()"<<endl;
		cout<<"2. Pop()"<<endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. isFull()"<<endl;
		cout<<"5. peek()"<<endl;
		cout<<"6. count()"<<endl;
		cout<<"7. change()"<<endl;
		cout<<"8. display()"<<endl;
		cout<<"9. Clear Screen"<<endl;

		cin>>option;
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Enter value to push into stack: "<<endl;
				cin>>value;
				s1.push(value);
				break;
			case 2:
				cout<<"Popped Value: "<<s1.pop()<<endl;
				break;
			case 3:
				if(s1.isEmpty())
					cout<<"Stack is Empty";
				else
					cout<<"Stack is not Empty";
				break;
			case 4:
				if(s1.isFull())
					cout<<"Stack is Full";
				else
					cout<<"Stack is not Full";
				break;
			case 5:
				cout<<"Enter the position of the value to be peeked: "<<endl;
				cin>>position;
				cout<<"Peek function called. Value at position "<<position<<" is: "<<s1.peek(position)<<endl;
				break;
			case 6:
				cout<<"Count function called. Number of Elements in the stack are: "<<s1.count()<<endl;
				break;
			case 7:
				cout<<"Enter the position of the item to be changed: "<<endl;
				cin>>position;
				cout<<"\nEnter new value: "<<endl;
				cin>>value;
				s1.change(position,value);
			case 8:
				cout<<"Display function called - "<<endl;
				s1.display();
				break;
			case 9:
				system("clear");	//clear screen
				break;
			default:
				cout<<"Enter a valid option number";
		}

	}while(option != 0);

	return 0;

}