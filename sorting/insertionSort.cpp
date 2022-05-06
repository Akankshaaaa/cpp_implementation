// implementation of Insertion Sort

#include <iostream>

using namespace std;

void insertionSort(int arr[])
{
	int j = 0;
	int key;

	for(int i = 1; i < 5; i++)
	{
		key = arr[i];	// select next element
		j = i - 1;

		// all values to the left of the key that are greater than the key
		while(j >= 0 && arr[j] > key)	
		{
			arr[j+1] = arr[j];	// arr[j] shifted to right
			j = j - 1;
		}
		arr[j+1] = key;	
	}
}


void printArray(int arr[])
{
	for(int i = 0; i < 5; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int myarr[5];

	cout<<"Enter 5 integers in random order "<<endl;

	for(int i = 0; i < 5; i++)
	{
		cin>>myarr[i];
	}

	cout<<"Unsorted Array: "<<endl;

	printArray(myarr);
	
	insertionSort(myarr);

	cout<<"Sorted Array: "<<endl;

	printArray(myarr);


	return 0;
}
