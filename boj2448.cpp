#include<stdio.h>

int n;
char arr[3333][6666];

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < 5; i++) arr[0][i] = '*';
	arr[1][1] = arr[1][3] = arr[2][2] = '*';
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n*2; j++){
			printf("%c", arr[i][j]);
		}
		puts("");
	}
}
