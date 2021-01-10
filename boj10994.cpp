#include<stdio.h>

int n, ar[999][999];

void f(int x, int v)
{
	for(int i = 1; i <= 1+(x-1)*4; i++)
		for(int j = 1; j <= 1+(x-1)*4; j++)
			if(i==1 || j==1 || i==1+(x-1)*4 || j==1+(x-1)*4)
				ar[i+v][j+v] = 1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		f(i, (n-i)*2);
	
	for(int i = 1; i <= 1+(n-1)*4; i++){
		for(int j = 1; j <= 1+(n-1)*4; j++){
			printf("%c", ar[i][j] ? '*' : ' ');
		}
		puts("");
	}
}
