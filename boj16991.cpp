#include<stdio.h>
#include<math.h>
#define INF 999999999
using namespace std;

int n, fin, Xpos[16], Ypos[16], vis[16];
double dp[16][1<<16];

double min(double x, double y)
{
	return x < y ? x : y;
}

double dist(int x, int y)
{
	return sqrt(pow(Xpos[x]-Xpos[y],2) + pow(Ypos[x]-Ypos[y],2));
}

double f(int x, int y, int cnt)
{
	if(cnt == n) return dist(x, 0);
	if(dp[x][y]) return dp[x][y];
	
	dp[x][y] = INF;
	vis[x] = 1;
	for(int i = 0; i < n; i++){
		if(i == x && vis[i]) continue;
		
		dp[x][y] = min(dp[x][y], dist(x, i) + f(i, y|(1<<i), cnt+1));
	}
	vis[x] = 0;
	
	return dp[x][y];
}

int main()
{
	scanf("%d", &n);
	fin = (1<<n)-1;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &Xpos[i], &Ypos[i]);
	}
	printf("%.17llf", f(0, 0, 1));
}
