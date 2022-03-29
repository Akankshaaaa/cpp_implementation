// bubble sort
#include <iostream>

using namespace std;

void swap(int arr[], int i, int j)
{
	int temp;
	temp = arr[j];
	arr[j] = arr[i];;
	arr[i] = temp;
}

void bubbleSort(int arr[], int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = i+1; j < size; j++)
		{
			if(arr[i] > arr[j])
			{
				swap(arr, i, j);
			}
		}
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

	bubbleSort(arr, size);

	printArray(arr, size);

	return 0;
}
