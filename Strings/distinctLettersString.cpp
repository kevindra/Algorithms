/**
* Cracking the Interview 
*
*	1.1 Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
*/

#include <iostream>

using namespace std;

// Method 1, using extra space 
bool isHavingDistinctLetters1(string s)
{
	int bits = 0;

	for(int i=0; i<s.size(); i++)
	{
		if(bits & (1<<(s[i]-'a')))
		{
			return false;
		}

		bits |= (1<<(s[i]-'a'));
	}
	return true;
}

int main()
{
	string s = "abcdd";

	cout<<"Answer: " << isHavingDistinctLetters1(s) <<endl;

	system("pause");
	return 0;
}