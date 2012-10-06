/**
* There are 2 sorted arrays A and B of size n each. 
* Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). 
* The complexity should be O(log(n)).
* 
* Example: 
* Array 1 = {1, 12, 15, 26, 38}
* Array 2 = {2, 13, 17, 30, 45}
* Merged Array = {1, 2, 12, 13, 15, 17, 26, 30, 38, 45} - 10 elements - median will be 10/2 th element 
* Output : 15!
*/

#include<iostream>

using namespace std;

/**
* O(n) solution
*
*	Maintain two counters for both the arrays.
* We know the median will be @ (n+n)/2 = nth index. (1-based)
* Simply keep incrementing the counting in increasing order of their values one by one. 
* Stop once (i+j) == n-1. Bingo! 
*/
int method1(int a1[], int a2[], int n, int m)
{
	int medianIndex = (n+m)/2 - 1;
	int median = 0;

	for(int i=0,j=0; i+j < medianIndex+1; )
	{
		if(i+j > medianIndex)
		{
			break;
		}

		if(a1[i] < a2[j])
		{
			median = a1[i];
			i++;
		}
		else if(a1[i] >= a2[j])
		{
			median = a2[j];
			j++;
		}
	}

	return median;
}

int method2(int a1[], int a2[], int s1, int e1, int s2, int e2)
{
	if(e1-s1 != e2-s2) 
	{
		cout<<"This method supports only equal size of arrays."<<endl;
		return -1;
	}

	if(e1-s1 < 0) return -1; // NOT valid input

	if(e1-s1 == 0)
	{
		return (a1[s1] + a2[s2])/2;
	}

	if(e1-s1 == 1)
	{
		return (max(a1[s1], a2[s2]) + min(a1[e1], a2[e2]) )/2;
	}

	int mid1 = (s1+e1)/2;
	int mid2 = (s2+e2)/2;

	if(a1[mid1] < a2[mid2])
	{
		return method2(a1, a2, mid1, e1, s2, mid2);
	}

	if(a1[mid1] > a2[mid2])
	{
		return method2(a1, a2, s1, mid1, mid2, e2);
	}

	if(a1[mid1] == a2[mid2])	return a1[mid1];

	return 0;
}

void printArray(int a[], int n)
{
		cout<<"Array: ";
		for(int i =0; i<n; i++) cout<<a[i]<<", ";
		cout<<endl;
}

int main()
{
	// 1, 2, 12, 13, 15, 17, 26, 30, 38

	//int a1[] = {1, 12, 15, 26, 38};
	//int a2[] = {2, 13, 17, 30, 45};
	//int a1[] = {1, 2, 3, 4, 5};
	//int a2[] = {6, 6, 7, 8, 9};
	int a1[] = {1,1,1,1,2};
	int a2[] = {2,2,2,2,2};
	int n = 5, m = 5;

	printArray(a1,n);
	printArray(a2,m);

	cout<<"Median: "<<method1(a1, a2, n, m)<<endl;
	cout<<"Median: "<<method2(a1, a2, 0, n-1, 0, m-1)<<endl;

	system("pause");
}