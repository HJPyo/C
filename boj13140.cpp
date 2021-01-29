/*
  HELLO
+ WORLD
-------
 XXXXXX 

H E L O W R D
0 1 2 3 4 5 6
*/

#include<stdio.h>

int n, vis[10], num[7];
bool flag = true;

void print()
{
	printf("  %d%d%d%d%d\n", num[0], num[1], num[2], num[2], num[3]);
	printf("+ %d%d%d%d%d\n", num[4], num[3], num[5], num[2], num[6]);
	printf("-------\n");
	printf("%7d", n);
}

void dfs(int x)
{
	if(flag == 0) return;
	if(x == 7){
		if(num[0] == 0 || num[4] == 0) return;
		int HELOWRD =
			(num[0] * 10000) +
			(num[1] * 1000) +
			(num[2] * 120) +
			(num[3] * 1001) +
			(num[4] * 10000) +
			(num[5] * 100) +
			(num[6]);
		if(HELOWRD == n){
			print();
			flag = false;
		}
	}
	
	for(int i = 0; i < 10; i++){
		if(vis[i] == 0){
			vis[i] = 1;
			num[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < 10; i++){
		dfs(i);
	}
	if(flag)
	printf("No Answer");
}
