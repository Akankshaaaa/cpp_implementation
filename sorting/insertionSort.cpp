// insertion sort
#include <iostream>

using namespace std;

void swap(int arr[], int min, int i)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[min];;
	arr[min] = temp;
}

void insertionSort(int arr[], int size)
{
	int min;
	int temp;
	for(int i = 0; i < size - 1; i++)
	{
		min = i;
		for(int j = i+1; j < size; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		swap(arr, min, i);
		
	}
}


void printArray(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}


int main()
{
	int arr[] = {6, 5, 4, 2, 3, 1, 7};
	int size = sizeof(arr)/sizeof(int);

	printArray(arr, size);

	insertionSort(arr, size);

	printArray(arr, size);

	return 0;
}
