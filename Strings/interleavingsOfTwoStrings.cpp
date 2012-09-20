/**
*	Given two strings str1 str2, write a function that prints all interleavings of the given two strings. You may assume that all characters in both strings are different.
* Example:
* Input: str1 = "AB",  str2 = "CD"
* Output:
    ABCD
    ACBD
    ACDB
    CABD
    CADB
    CDAB

* Input: str1 = "AB",  str2 = "C"
* Output:
    ABC
    ACB
    CAB
*
* An interleaved string of given two strings preserves the order of characters in individual strings. For example, in all the interleavings of above first example, ‘A’ comes before ‘B’ and ‘C’ comes before ‘D’.
*/
#include <iostream>
#include <string>

using namespace std;

void print(string s1, string s2, string result, int i, int j)
{	
	if(result.length() == s1.length() + s2.length())
	{
		cout<<result<<endl;
		return;
	}

	if(i < s1.length())
	{
		print(s1,s2, result + s1[i], i+1, j);
	}

	if(j < s2.length())
	{
		print(s1,s2, result + s2[j], i, j+1);
	}
}

int main()
{
	string s1, s2;
	s1 = "AB";
	s2 = "CD";

	print(s1,s2,"", 0, 0);

	system("pause");
	return 0;
}