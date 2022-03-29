// Linked list : Insert a node at the beginning

#include <iostream>

using namespace std;

struct Node{

	int data;
	Node* next;
};

//pointer to head
Node* head;		//global variable

void Insert(int x)
{
	Node* temp = new Node;		//create a new node and store it's address in temp
	temp -> data = x;		//fill new node with data x
	temp -> next = head;	//// fill address of the head in next part. if list is empty, then head will be null
	head = temp;	// head points to new node
}

void Print()
{
  cout<<"List : ";
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<temp -> data<<" ";
		temp = temp -> next;
	}
	cout<<endl;
}

int main()
{
	head = NULL;	//empty list

	cout<<"How many numbers? "<<endl;
	int n, x;
	cin>>n;

	for(int i = 0; i < n; i++)
	{
		cout<<"Enter number: "<<endl;
		cin>>x;
		Insert(x);
		Print();
	}

	return 0;
}
