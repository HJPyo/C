#include<stdio.h>

int n;
char ar[105][105];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		char tmp[105];
		scanf("%s", &tmp);
		for(int j = 0; j < n; j++){
			ar[i][j] = tmp[j];
			printf("%c ", ar[i][j]);
		}
		puts("");
	}
}
