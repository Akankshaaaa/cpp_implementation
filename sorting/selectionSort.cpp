//selection sort
#include <iostream>

using namespace std;

void swap(int arr[], int min, int i)
{
	int temp;
	temp = arr[min];
	arr[min] = arr[i];;
	arr[i] = temp;
}

void selectSort(int arr[], int size)
{
	int min;
	int temp;

	for(int i = 0; i < size - 1; i++)
	{
		min = i;
		for(int j = i+1; j < size; j++)
		{
			if(arr[min] > arr[j])
			{
				min = j;
			}
		
		swap(arr, min, i);
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
	int arr[] = {5, 4, 1, 3, 2};
	int size = sizeof(arr)/sizeof(int);

	printArray(arr, size);

	selectSort(arr, size);

	printArray(arr, size);

	return 0;
}