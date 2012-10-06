/**
* Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. 
*
* For example: let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5,6,7,8,9 in the given array.
*
* Solution 1: O(n*k)
* Solution 2: (using min-heap) O(n*logk)
*/

#include <iostream>

using namespace std;

// to achieve O(n*logk), we have to heapify the every window of k starting from i
void heapify(int a[], int start, int i, int k, int n)
{
	// slightly modified 
	// normalized the index to calculate the left and right indexes
	int left = 2*(i-start) + 1 + start;
	int right = 2*(i-start) + 2 + start;

	// since we are heapifying just the window 
	// hence the boundary will be min(i+k+1, n)
	int smallest = i;
	if(left < min(i+k+1, n) && a[left] < a[i]) smallest=left;
	if(right < min(i+k+1, n) && a[right] < a[smallest]) smallest=right;

	if(smallest != i)
	{
		swap(a[smallest], a[i]);
		heapify(a, start, smallest, k, n);
	}
}
// this method uses heapifies the array at each index.
void sort2(int a[], int n, int k)
{
	for(int i=0; i<=k; i++)
	{
		heapify(a,i,i,k-i,n);
	}
			cout<<" after first heap ";
			for(int j=0; j<=k; j++)
				cout<<a[j]<<" ";
			cout<<endl;
	for(int i=k+1; i<n; i++)
	{
		heapify(a, i, i, k, n);
	}
}

// simple O(n*k) solution 
void sort1(int a[], int n, int k)
{
	for(int i=0; i<n; i++)
	{
		int mn = i;
		for(int j=i; j<=min(i+k,n-1); j++)
		{
			if(a[j] < a[mn]) mn=j;
		}
		swap(a[i], a[mn]);
	}
}

void heapifyNew(int a[], int start, int i, int k, int n)
{
	int left = 2*(i-start)+1+start;
	int right = 2*(i-start)+2+start;

	int smallest = a[i];
	if(left < min(start+k+1, n) && a[left] < a[smallest]) smallest = left;
	if(right < min(start+k+1, n) && a[right] < a[smallest]) smallest = right;

	if(i != smallest)
	{
		swap(a[smallest], a[i]);
		heapifyNew(a, start, smallest, k, n);
	}
}

void minHeapify(int a[], int k)
{
	int i = k/2;
	while(i > 0 && a[i] > a[i/2])
	{
		swap(a[i], a[i/2]);
		i = i/2;
	}
}


void solve(int a[], int n, int k)
{
	int i = (k-1)/2;
	while(i--)
	{
		heapifyNew(a,0,i,k,n);
	}
	//heapifyNew(a,k);

	for(int i=k+1; i<n; i++)
	{
		swap(a[i], a[i-k+2]);
		heapifyNew(a, i, i, k, n);
	}
}

int main()
{
	//1,2,3,4,5,6,7,8
  //4,1,6,5,2,3,7,8
	int a[] = {4,1,6,5,2,3,7,8};//{2,6,3,12,56,8};//{3,4,1,2,6,5};
	int n = 6, k=4;

	//sort1(a, n, k);
	// sort2(a,n,k);
	solve(a,n,k);

	cout<<"Sorted array: ";
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<", ";
	}
	cout<<endl;

	system("pause");
}