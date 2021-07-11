#include<iostream>
using namespace std;

void Merge(int a[], int left, int right, int mid)
{


	
	//get the number of elements for the left half
	int n1 = mid - left + 1;
	//get the number of elements for the right half
	int n2 = right - mid;
	//create a temp arrays to store sorted values
	int *leftArr = new int [n1];
	int* rightArr = new int[n2];
	
	//copying the unsorted array left half to the temporay leftArr
	for (int i = 0; i < n1; i++)
	{
		leftArr[i] = a[left + i];
	}
	//copying the unsorted array right half to the tempoary rightArr
	for (int j = 0; j < n2; j++) 
	{
		rightArr[j] = a[mid + 1 + j];
	}
	//index for the subArray left half
	int i = 0;
	//index for the original arr
	int k = left;
	// index for the subArray right half arr
	int j = 0;
	//starting from index 0, go through all the elements of the subarray.
	//if one subarray Index reaches max element of the subarray elements
	//exit the loop
	while (i < n1 && j < n2)
	{
		//checks if left subarray is less then the right subarray
		//if so merge that value to the orignal array and increment k
		if (leftArr[i] <= rightArr[j])
		{
			
			a[k] = leftArr[i];
			i++;
		}
		else
		//add the right temp array to original array
		{
			a[k] = rightArr[j];
			j++;
		}
		k++;
	}
	//checks if there is any remaining values left for the left sub array that has not been added
	while (i < n1)
	{
		a[k] = leftArr[i];
		i++;
		k++;
	}
	//checks if there is any remaining values right for the left sub array that has not been added
	while (j < n2)
	{
		a[k] = rightArr[j];
		j++;
		k++;
	}

	//check of initial index on left side is less then inital index of right side then increment. 
}
void MergeSort(int a[], int left, int right)
{
	cout << "Left " << left << " Right " << right << endl;
	
	if (left >= right) {
		return;//returns recursively
	}
	
	if (left < right)
	{
		//get the middle index
		int pivot = (left + right) / 2;
		//split the array for the left half
		MergeSort(a, left, pivot);
		//split the array for the right half
		MergeSort(a, pivot+1,right);
		//Merge the two halves together
		Merge(a, left, right, pivot);
	}
}
void Display(int a[], int size)
{
	cout << "Sorted Elements: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i]<<" ";
	}
}
int main()
{
	
	int a[8] = { 3,1,2,5,4,7,22,26 };
	int size = sizeof(a) / sizeof(a[0]);
	cout << "Unsorted Elements ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	MergeSort(a, 0, size-1);
	Display(a, size);
}