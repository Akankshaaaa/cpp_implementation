// implementation of singly linked list

#include <iostream>

using namespace std;

class Node{
public:
	int key;
	int data;
	Node *next;

	Node()
	{
		key = 0;
		data = 0;
		next = NULL;
	}

	Node(int k, int d)
	{
		key = k;
		data = d;
	}
};

class singlyLL{
public:
	Node *head;

	singlyLL()
	{
		head = NULL;
	}

	singlyLL(Node *n)	//pass by address - takes the address of the node
	{
		head = n;	// head pointer will store address of node
	}

	// 1. traverse the list and check if node exists
	Node* nodeExists(int k)	// method that will return a pointer
	{
		Node *temp = NULL;

		Node *ptr = head;	// pointing to head
		while(ptr != NULL)	// if list is empty
		{
			// key value of node matches with the passed key value
			if(ptr->key == k)
			{
				temp = ptr;
			}
			ptr = ptr->next; // store address of the next node
		}
		return temp;
	}

	// 2. append a node to the list
	void appendNode(Node *n)
	{
		if(nodeExists(n -> key) != NULL)	// node with same key already exists
		{
			cout<<"Node already exists with key value: "<<n->key<<"\nAppend node with different key value"<<endl;
		}
		else
		{
			if(head == NULL)	// list is empty
			{
				head = n;
				cout<<"Node appended."<<endl;
			}
			else
			{
				Node* ptr = head;	// pointing to head

				// will run until we reach the end of the list
				while(ptr->next != NULL)	// check next part of current node
				{
					ptr = ptr->next; // store address of the next node
				}
				ptr->next = n;
				cout<<"Node appended"<<endl;
			}
		}


	}

	// 3. prepend a node to the list
	void prependNode(Node *n)
	{
		if(nodeExists(n->key) != NULL)
		{
			cout<<"Node already exists with key value: "<<n->key<<"\nAppend node with different key value"<<endl;
		}
		else
		{
			n->next = head;		// next part of current node will haev the address of first node
			head = n;	// store new node in head
		}
	}

	// 4. insert a node after particular node in the list
	void insertNode(int k, Node *n)		// takes key value and node
	{
		Node *ptr = nodeExists(k);
		if(ptr == NULL)		// if key does not exist
		{
			cout<<"No node exists with key value: "<<k<<endl;
		}
		else
		{
			// check if key is unique
			if(nodeExists(n->key) != NULL)	
			{
			cout<<"Node already exists with key value: "<<n->key<<"\nAppend node with different key value"<<endl;
			}
			else
			{
				n->next = ptr->next; 	// store next part of current node is next part of new node
				ptr->next = n;	// store address of new node in next part of current node
				cout<<"Node inserted."<<endl;
			}

		}
	}

	// 5. Delete node by unique key
	void deleteNode(int k)
	{	
		// list is empty
		if(head == NULL)
		{
			cout<<"Cannot delete. List is empty"<<endl;
		}

		// list is not empty
		else if(head != NULL)
		{
			// key matches head
			if(head->key == k)
			{
				head = head->next;
				cout<<"Node unlinked with key value: "<<k<<endl;
			}
			else
			{
				Node *temp = NULL;
				Node *prevptr = head;
				Node *currentptr = head->next;
				while(currentptr != NULL)	// run until end of list
				{
					// key matches
					if(currentptr->key == k)
					{
						temp = currentptr;	// store current node
						currentptr = NULL;	// unlink current node from next node
					}
					// key does not match
					else
					{
						// move to next iteration
						prevptr = prevptr->next;
						currentptr = currentptr->next;
					}
				}
				if(temp != NULL)
				{
					// unlink previous node from current node
					prevptr->next = temp->next;
					cout<<"Node unlinkedwith key value: "<<k<<endl;
				}
				else
				{
					cout<<"Node doesn't exist with key value: "<<k<<endl;
				}
			}
		}
	}

	// 6. update node
	void updateNode(int k, int d)	// takes key and data
	{
		Node *ptr = nodeExists(k);
		if(ptr != NULL)
		{
			ptr->data = d;
			cout<<"Node data updated.";
		}
		else
		{
			cout<<"Node does not exist with key value: "<<k<<endl;
		}
	}

	// 7. print list
	void printList()
	{
		if(head == NULL)
		{
			cout<<"No nodes in the singly linked list";
		}
		else
		{
			cout<<endl<<"Singly Linked List Values : "<<endl<<endl;
			Node *temp = head;

			while(temp != NULL)
			{
				cout<<"("<<temp->key<<","<<temp->data<<"), ";
				temp = temp->next;
			}
		}
	}
};

int main()
{

	singlyLL s;
	int option;
	int key1, k1, data1;

	do
	{
		cout<<"\nSelect operation no. Enter 0 to exit"<<endl;
		cout<<"1. appendNode()"<<endl;
		cout<<"2. prependNode()"<<endl;
		cout<<"3. insertNode()"<<endl;
		cout<<"4. deleteNode()"<<endl;
		cout<<"5. updateNode()"<<endl;
		cout<<"6. print()"<<endl;
		cout<<"7. Clear Screen()"<<endl;

		cin>>option;

		Node *n1 = new Node();

		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Enter key and data of the node to be appended: "<<endl;
				cin>>key1;
				cin>>data1;
				n1->key = key1;
				n1->data = data1;
				s.appendNode(n1);
				break;
			case 2:
				cout<<"Enter key and data of the node to be preppended: "<<endl;
				cin>>key1;
				cin>>data1;
				n1->key = key1;
				n1->data = data1;
				s.prependNode(n1);
				break;
			case 3:
				cout<<"Enter existing key after which you want to inset new node: "<<endl;
				cin>>k1;
				cout<<"Enter key and data of the node to be inserted: "<<endl;
				cin>>key1;
				cin>>data1;
				n1->key = key1;
				n1->data = data1;
				s.insertNode(k1,n1);
				break;
			case 4:
				cout<<"Enter key of the node to be deleted: "<<endl;
				cin>>k1;
				s.deleteNode(k1);
				break;
			case 5:
				cout<<"Enter key and NEW data of the node to be updated: "<<endl;
				cin>>key1;
				cin>>data1;
				s.updateNode(key1,data1);
				break;
			case 6:
				s.printList();
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