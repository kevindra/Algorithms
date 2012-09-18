/**
*	Design an algorithm that, given a list of n elements in an array, finds all the elements that appear more than n/3 times in the list.
*	The algorithm should run in linear time. (n >=0 )
*
*	You are expected to use comparisons and achieve linear time. No hashing/excessive space/ and don't use standard linear time deterministic selection algo
*/
#include <iostream>

using namespace std;


void findMajorities(int a[], int n, int &m1, int &m2)
{
	int count = 1; m1 = 0;
	
	// loop through all the array elements
	for(int i=0; i<n; i++)
	{
		// if a[i] is same as the last calculated majority element, then increase the count
		if(a[i] == a[m1]) count++;
		// else decrease the count
		else count--;

		// if count becomes zero
		if(count == 0)
		{
			// persist the current majority index to m2 and current index to m1
			// and set count = 1 
			m2 = m1;
			m1 = i;
			count = 1;
		}
	}
}

// current m1 & m2 will only be the majorities if their count > n/3
// to check the same we need to loop through the array again 
// and count the occurance of both the elements i.e. a[m1] & a[m2]
// if count > n/3 then they are majority elements
void printActualMajorities(int *a, int n, int m1, int m2)
{
	int countM1=0, countM2=0;

	for(int i=0; i<n; i++)
	{
		if(a[i] == a[m1]) countM1++;
		else if(a[i] == a[m2]) countM2++;
	}

	if(countM1 > n/3) cout<<"Majority one: "<<a[m1]<<endl;
	if(countM2 > n/3) cout<<"Majority two: "<<a[m2]<<endl;

	if(countM1 <= n/3 && countM2 <= n/3) cout<<"No Majorities!" <<endl; 
}

int main()
{
	int a[] = {1,2,3,1,3,3,1,1,3};
	int n = 9;

	int m1, m2;
	findMajorities(a, n, m1, m2);

	printActualMajorities(a, n, m1, m2);

	system("pause");
}