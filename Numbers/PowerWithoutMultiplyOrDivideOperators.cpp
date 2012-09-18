#include<iostream>

using namespace std;

#define SIZE 100

int mulM[SIZE][SIZE], powM[SIZE][SIZE];

int mul(int x, int y)
{
	if(mulM[x][y] != 0) return mulM[x][y];

	if(y == 0) return 0;
	if(y == 1) return x;

	return mulM[x][y] = (x + mul(x, y-1));
}

int pow(int a, int n)
{
	if(powM[a][n] != 0) return powM[a][n];

	if(n==0) return powM[a][n] = 1;
	if(n==1) return powM[a][n] = a;

	if(n%2 == 0)
	{
		return powM[a][n] = mul(pow(a,n>>1),pow(a,n>>1));
	}
	else
	{
		return powM[a][n] = mul(mul(a, pow(a,n>>1)), pow(a,n>>1));
	}
}

int main()
{
	int a = 2, n = 12;
	
	/*
	for(a = 1; a < 10; a++)
	{
		for(n = 1; n < 10; n++)
		{
			if(pow((double)a, (double)n) != pow(a,n)){ cout<<"Miss!! @" <<a<<" " <<n<<endl; } 
			
		}
	}
	*/
	cout<<"pow: " << pow(a, n) <<endl;

	cout<<"mul: " << mul(a, n) <<endl;
	system("pause");
}