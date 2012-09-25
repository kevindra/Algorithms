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
	int medianIndex = (n+m)%2==0?((n+m)/2)-1:(n+m)/2;
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

int main()
{
	// 1, 2, 12, 13, 15, 17, 26, 30, 38

	int a1[] = {1, 12, 15, 26, 38};
	int a2[] = {2, 13, 17, 30, 45};
	int n = 5, m = 5;

	cout<<"Median: "<<method1(a1, a2, n, m)<<endl;

	system("pause");
}