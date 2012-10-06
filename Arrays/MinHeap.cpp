#include <iostream>

using namespace std;
class MinHeap
{
	int *a, n;

public:
	MinHeap(int a[], int n);

	// to min heapify at a given index
	void minHeapify(int i);

	// to get the left child of ith node
	int left(int i){ return (2*i+1); }

	// to get the right child of ith node
	int right(int i){ return (2*i+2); }

	// to get the min 
	int extractMin();

	// remove min and add new value
	int replaceMin(int x);
};
// Constructor
MinHeap::MinHeap(int arr[], int size)
{
	a = arr; n = size; // store the array

	int i = (n-1)/2; //after i all the elements of array will be leaves, hence ignore them
	while(i >= 0)
	{
		minHeapify(i); i--;
	}
}

// method implementations
void MinHeap::minHeapify(int i)
{
	int l = left(i);
	int r = right(i);

	int smallest = i;
	if(l < n && a[l] < a[smallest]) smallest = l;
	if(l < n && a[r] < a[smallest]) smallest = r;

	if(i != smallest)
	{
		swap(a[i], a[smallest]);
		minHeapify(smallest);
	}
}

// extract min
int MinHeap::extractMin()
{
	int minElement = a[0];

	if(n > 1)
	{
		a[0] = a[n-1];
		n--;
		minHeapify(0);
	}

	return minElement;
}

int MinHeap::replaceMin(int x)
{
	int minElement = a[0];
	a[0] = x;
	if(minElement < x) minHeapify(0);
	return minElement;
}

int main()
{
	int a[] = {4,1,6,5,2};
	int n = 5;

	MinHeap mh(a, n);

	cout<<"After heapify: ";

	for(int i=0; i<n; i++)
	{
		cout<<a[i] << " ";
	}
	system("pause");
}