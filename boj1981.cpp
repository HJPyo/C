#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int n, ar[102][102];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
struct tuple{ int MIN, MAX, CHA; }dp[102][102];

int f(int x, int y)
{
	if(x == n && y == n) return 0;
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	memset(ar, -1, sizeof(ar));
	
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	printf("%d", f(1,1));
}
