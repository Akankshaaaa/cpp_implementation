// implementation of binary search

#include <iostream>

using namespace std;

// takes array, start index, end index, element to be searched as input
int binarySearch(int arr[], int start, int end, int x)
{

	if(start <= end)
	{
		int mid = start + (end - start)/2;
		if(arr[mid] == x)
		{
			return mid;
		}
		else if(arr[mid] < x)
		{
			return(binarySearch(arr, mid + 1, end, x));
		}
		else
		{
			return(binarySearch(arr, start, mid - 1, x));
		}
	}
	return -1;

}


int main()
{
	int num;
	int my_arr[10];
	int output;

	cout<<"Enter 10 integers in sorted order "<<endl;

	for(int i = 0; i < 10; i++)
	{
		cin>>my_arr[i];
	}

	cout<<"Enter the element to be searched in the array"<<endl;

	cin>>num;

	output = binarySearch(my_arr, 0, 9, num);

	if(output == -1)
	{
		cout<<"Match not found."<<endl;
	}
	else
	{
		cout<<"Match found at index "<<output<<endl;
	}

	return 0;
}