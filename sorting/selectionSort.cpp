// implementation of Selection Sort

#include <iostream>

using namespace std;

void swap(int arr[], int a, int b)
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];;
	arr[b] = temp;
}

void selectionSort(int arr[])	// arrays are passed by address in c++
{
	for(int i = 0; i < 4; i++)
	{
		int min = i;

		// find min element
		for(int j = i+1; j < 5; j++)
		{
			// for ascending order. if sorting in descending order then simply flip the operator
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		if(min != i)
		{
			// swap min element with ith element
			swap(arr, i, min);
		}
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
	
	selectionSort(myarr);

	cout<<"Unsorted Array: "<<endl;

	printArray(myarr);

	return 0;
}
