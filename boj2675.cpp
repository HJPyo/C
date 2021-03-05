#include<stdio.h>

int k;

int main()
{
	scanf("%d", &k);
	for(int Test = 0; Test < k; Test++){
		int n;
		char str[22];
		scanf("%d %s", &n, &str);
		for(int i = 0; str[i] != NULL; i++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%c", str[i]);
			}
		}
		printf("\n");
	}
}
