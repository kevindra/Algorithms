/**
* 
*/
#include <iostream>

using namespace std;

int findMajority(int *a, int n)
{
	int majorityIndex=0, count=1;

	// loop through all the numbers
	for(int i=0;i<n;i++)
	{
		// if a[i] is same as the last calculated majority index element, then increase the count 
		if(a[i] == a[majorityIndex]) count++;
		// else decrease the count 
		else count--;

		// if count becomes zero, choose the current a[i] as the majority element
		// and set count to 1 again.
		if(count == 0)
		{
			majorityIndex = i;
			count = 1;
		}
	}

	// return a[majorityIndex].. it might or might not be the majority
	// to check the same we have to check the count of this element 
	// if the count > n/2 then majority element otherwise there is no 
	// majority element in the array.
	return a[majorityIndex];
}

// find out if the candidate is really a majority element.
bool isMajority(int *a, int n, int candidate)
{
	int count = 0;
	for(int i =0; i<n; i++)
		if(a[i] == candidate) count++;
		
	return count > n/2;
}

int main()
{
	int a[] = {2,2,2,1,2,1,2,4,2,1};
	int n = 10;

	int cand = findMajority(a,n);

	if(isMajority(a,n,cand))
	{
		cout<<"Majority element: " << cand <<endl;
	}
	else
	{
		cout<<"No Majority" <<endl;
	}

	system("pause");
}