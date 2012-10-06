/**
*	1.2 Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)
*/

#include <iostream>
#include <algorithm>

using namespace std;

void reverse(char *s, int i)
{
	int len = strlen(s);
	
	char temp = s[i];
	s[i] = s[len-i-1];
	s[len-i-1] = temp;

	if(i < len/2)	reverse(s, i+1);
}

int main()
{
	char *s = new char[5];
	cin>>s;

	//for(int i =0; i< strlen(s); i++)
	//{
	//	cout<<s[i]<<" ";
	//}

	for(int i=0; i<strlen(s)/2; i++)
	{
		cout<<s[i]<<" "<<s[strlen(s)-1-i]<<endl;
		char t = s[i];
		s[i] = s[strlen(s)-1-i];
		s[strlen(s)-1-i] = t;
	}

	cout<<s<<endl;
	reverse(s,0);
	cout<<s<<endl;

	system("pause");
	return 0;
}