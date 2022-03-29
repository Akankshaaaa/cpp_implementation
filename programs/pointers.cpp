// implementation of pointers

#include <iostream>

using namespace std;

int main()
{
	int x = 5, y = 10;

	//reference of x
	int &ref = x;

	//pointer of x
	int *ptr = &x;

	cout<<"Address of "<<ref<<" is "<<&ref<<endl; 
	cout<<"Pointer "<<ptr<<" is pointing to "<<*ptr<<endl; 
	return 0;
}
