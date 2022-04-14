// implementation of doubly linked list

#include <iostream>

using namespace std;

class Node{
public:
	int key;
	int data;
	Node* next;		// pointer to next node
	Node* previous;	// pointer to previous node

	Node()
	{
		key = 0;
		data = 0;
		next = NULL;
		previous = NULL;
	}

	Node(int k, int d)
	{
		key = k;
		data = d;
	}

};

class DoublyLinkedList{
public:
	Node* head;

	DoublyLinkedList()
	{
		head = NULL;
	}

	DoublyLinkedList(Node* n)
	{
		head = n;
	}

	// 1. check if node exists using key
	Node* nodeExists(int k)	// if node exists with the key, return the address of the node
	{
		Node* temp = NULL;
		Node* ptr = head;

		//traverse through doubly linked list and check if node exists
		while(ptr != NULL)
		{
			if(ptr->key == k)
			{
				temp = ptr;
			}
			ptr = ptr->next;
		}

		return temp;
	}

	// 2. Append a node to the list
	void appendNode(Node* n)
	{
		if(nodeExists(n->key) != NULL)
		{
			cout<<"Node already exists eith key value : "<<n->key<<". Appeend node with diffeent key"<<endl;
		}
		else
		{
			// if list is empty
			if(head == NULL)
			{
				head = n;
				cout<<"Node appended as Head Node"<<endl;
			}
			else
			{
				Node* ptr = head;
				while(ptr->next != NULL)
				{	
					// move to next node
					ptr = ptr->next;
				}
				ptr->next = n;
				n-> previous = ptr;
				cout<<"Node appended"<<endl;
			}
		}
	}

	// 3. prepend node
	void prependNode(Node* n)
	{

		if(nodeExists(n->key) != NULL)
		{
			cout<<"Node alrady exists with key value : "<<n->key<<". Append node with diffeent key"<<endl;
		}
		else
		{
			// if list is empty
			if(head == NULL)
			{
				head = n;
				cout<<"Node appended as Head Node"<<endl;
			}
			else
			{

			
				head->previous = n;
				n->next = head;

				head = n;
				cout<<"Node prepended"<<endl;
			}
		}

	}

	// 4. Insert a node after a node in the list
	void insertNodeAfter(int k, Node* n)
	{
		Node* ptr = nodeExists(k);
		if(ptr == NULL)
		{
			cout<<"No node exists with key value : "<<k<<endl;
		}
		else
		{
			if(nodeExists(n->key))
			{
				cout<<"Node alrady exists with key value : "<<n->key<<". Append node with diffeent key"<<endl;
			}
			else
			{
				Node* nextNode = ptr->next;
				// insert at end of the list
				if(nextNode == NULL)
				{
					ptr->next = n;
					n->previous = ptr;
					cout<<"Node inserted at the end."<<endl;
				}
				// insert in between
				else
				{
					n->next = nextNode;
					nextNode->previous = n;
					n->previous = ptr;
					ptr->next = n;
					cout<<"Node inserted in between."<<endl;
				}
			}
		}
	}

	// 5. Delete node y unique key
	void deleteNodeByKey(int k)
	{
		Node* ptr = nodeExists(k);
		if(ptr == NULL)
		{
			cout<<"No node exists with key value : "<<k<<endl;
		}
		else
		{
			// if node is head node
			if(head->key == k)
			{
				head = head->next;
				cout<<"Node unlinked with key value : "<<k<<endl;
			}
			else
			{
				Node* nextNode = ptr->next;
				Node* prevNode = ptr->previous;

				// delete node at the end
				if(nextNode == NULL)
				{
					prevNode->next = NULL;
					cout<<"Node deleted at the end."<<endl;
				}

				//deleting node in between
				{
					prevNode->next = nextNode;
					nextNode->previous = prevNode;
					cout<<"Node deletedin between."<<endl;
				}

			}
		}

	}

	// 6. update node
	void updateNodeByKey(int k, int d)
	{
		Node* ptr = nodeExists(k);
		if(ptr != NULL)
		{
			ptr->data = d;
			cout<<"No node exists with key value : "<<k<<endl;
		}
		else
		{
			cout<<"Node does not exist with key value : "<<k<<endl;
		}
	}

	// 7. print list
	void printList()
	{
		if(head == NULL)
		{
			cout<<"No node in the list."<<endl;
		}
		else
		{
			cout<<endl<<"Doubly Linked List values : ";
			Node* temp = head;
			while(temp != NULL)
			{
				cout<<"("<<temp->key<<","<<temp->data<<") <--> ";
				temp = temp->next;
			}
		}
	}

};


int main()
{

	DoublyLinkedList obj;
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

		Node* n1 = new Node();

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