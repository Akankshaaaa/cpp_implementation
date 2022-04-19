// implementation of circular linked list

#include<iostream>

using namespace std;

class Node{
public:
	int key;
	int data;
	Node* next;

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

class CircularLinkedList
{
public:
	Node* head;

	CircularLinkedList()
	{
		head = NULL;
	}

	// 1. traverse the list and check if node exists
	Node* nodeExists(int k)
	{

		Node* temp = NULL;
		Node* ptr = head;

		// if list is empty
		if(ptr == NULL)
		{
			return temp;
		}
		// if list is not empty
		else
		{
			do
			{
				if(ptr->key == k)
				{
					temp = ptr;
				}
				ptr = ptr->next;
			}while(ptr!=head);	// reached end of the list
			return temp;
		}

	}

	// 2. append a node to the list
	void appendNode(Node* new_node)
	{
		if(nodeExists(new_node->key) != NULL)
		{
			cout<<"Node already exists with key value: "<<new_node->key<<"\nAppend node with different key value"<<endl;
		}
		else
		{
			// list is empty
			if(head == NULL)
			{
				head = new_node;
				new_node->next = head;	// next pointer of head will point to head itself
			}
			// list is not empty
			else
			{
				Node* ptr = head;
				while(ptr->next != head)
				{
					ptr = ptr->next;
				}
				ptr->next = new_node;
				new_node->next = head;
				cout<<"Node appended."<<endl;
			}
		}
	}

	// 3. prepend a node to the list
	void prependNode(Node* new_node)
	{
		if(nodeExists(new_node->key) != NULL)
		{
			cout<<"Node already exists with key value: "<<new_node->key<<"\nAppend node with different key value"<<endl;
		}
		else
		{
			// list is empty
			if(head == NULL)
			{
				head = new_node;
				new_node->next = head;	// next pointer of head will point to head itself
			}
			else
			{
				Node* ptr = head;
				while(ptr->next != head)
				{
					ptr = ptr->next;
				}	
				ptr->next = new_node;	// last element will point to new node i.e the new head
				new_node->next = head;
				head = new_node;
				cout<<"Node prepended."<<endl;
			}			
		}
	}

	// 4. insert a node after particular node in the list
	void insertNodeAfter(int k, Node *new_node)
	{
		Node* ptr = nodeExists(k);
		if(ptr == NULL)
		{
			cout<<"No node exists with key value: "<<k<<endl;
		}
		else
		{
			if(nodeExists(new_node->key) != NULL)
			{
				cout<<"Node already exists with key value: "<<new_node->key<<"\nAppend node with different key value"<<endl;
			}
			else
			{
				// insertion at end of the list
				if(ptr->next == head)
				{
					new_node->next = head;
					ptr->next = new_node;
					cout<<"Node inserted at the end."<<endl;
				}
				else
				{
					new_node->next = ptr->next;
					ptr->next = new_node;
					cout<<"Node inserted in between."<<endl;
				}
			}
		}
	}

	// 5. Delete node by unique key
	void deleteNodeByKey(int k)
	{
		Node* ptr = nodeExists(k);
		if(ptr == NULL)
		{
			cout<<"Node doesn't exist with key value: "<<k<<endl;
		}
		else
		{	
			// delete head node
			if(ptr == head)
			{
				// if list has single element
				if(head->next == head)
				{
					head = NULL;
					cout<<"Head node unlinked... List empty";
				}
				// if list has more than one element
				else
				{
					Node* ptr = head;
					while(ptr->next != head)
					{
						ptr = ptr->next;
					}
					ptr->next = head->next;
					head = head->next;	// set new head
				}
			}
			// delete any other node
			else
			{
				Node* temp = NULL;
				Node* prevptr = head;
				Node* currentptr = head->next;
				while(currentptr != NULL)
				{
					if(currentptr->key == k)
					{
						temp = currentptr;
						currentptr = NULL;
					}
					else
					{
						prevptr = prevptr->next;
						currentptr = currentptr->next;
					}
				}

				prevptr->next = temp->next;
				cout<<"Node unlinked with key value : "<<k<<endl;
			}
		}
	}

	// 6. update node
	void updateNodeByKey(int k, int new_data)
	{
		Node *ptr = nodeExists(k);
		if(ptr != NULL)
		{
			ptr->data = new_data;
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
			cout<<"No nodes in the circular linked list";
		}
		else
		{
			cout<<endl<<"Circular Linked List Values : "<<endl<<endl;
			Node *temp = head;

			do
			{
				cout<<"("<<temp->key<<","<<temp->data<<"), ";
				temp = temp->next;
			}
			while(temp != head);
		}
	}
};


int main()
{

	CircularLinkedList obj;
	int option;
	int key1, k1, data1;

	do
	{
		cout<<"\nSelect operation no. Enter 0 to exit"<<endl;
		cout<<"1. appendNode()"<<endl;
		cout<<"2. prependNode()"<<endl;
		cout<<"3. insertNodeAfter()"<<endl;
		cout<<"4. deleteNodeByKey()"<<endl;
		cout<<"5. updateNodeByKey()"<<endl;
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
				obj.appendNode(n1);
				break;
			case 2:
				cout<<"Enter key and data of the node to be preppended: "<<endl;
				cin>>key1;
				cin>>data1;
				n1->key = key1;
				n1->data = data1;
				obj.prependNode(n1);
				break;
			case 3:
				cout<<"Enter existing key after which you want to inset new node: "<<endl;
				cin>>k1;
				cout<<"Enter key and data of the node to be inserted: "<<endl;
				cin>>key1;
				cin>>data1;
				n1->key = key1;
				n1->data = data1;
				obj.insertNodeAfter(k1,n1);
				break;
			case 4:
				cout<<"Enter key of the node to be deleted: "<<endl;
				cin>>k1;
				obj.deleteNodeByKey(k1);
				break;
			case 5:
				cout<<"Enter key and NEW data of the node to be updated: "<<endl;
				cin>>key1;
				cin>>data1;
				obj.updateNodeByKey(key1,data1);
				break;
			case 6:
				obj.printList();
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