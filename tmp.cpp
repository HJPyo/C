#include<stdio.h>

int main()
{
	int n = 1000, ar[1001] = {};
	
	ar[1] = 1;
	
	for(int i = 2; i <= n; i++)
	{
		if(ar[i] != 0)
		{
			continue;
		}
		for(int j = 2; i * j <= n; j++)
		{
			ar[i * j] = 1;
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(ar[i] == 0){
			printf("%d\n", i);
		}
	}
	
	return 0;
}
