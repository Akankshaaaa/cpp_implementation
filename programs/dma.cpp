// dynamic memory allocation
#include <iostream>

using namespace std;

int main()
{
	int size;
	int *ptr;

	cout<<"Enter array size "<<endl;
	cin>>size;

	// dynamically allot size to array
	ptr = new int[size];

	cout<<"enter array elements "<<endl;

	for(int i; i < size; i++)
	{
		cin>>ptr[i];
	}

	cout<<"Array : "<<endl;

	for(int i = 0; i < size; i++)
	{
		cout<<ptr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
