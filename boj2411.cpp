#include<stdio.h>
#include<vector>
using namespace std;

int n, m, good, wall, ar[102][102];
vector< vector<int> >dp(102,vector<int>(102,0));

int f(int x, int y, int get)
{
	if(x == n && y == m){
		if(get == good) return 1;
		else return 0;
	}
	if(dp[x][y]) return dp[x][y];
	if(ar[x][y] == 1 || x > n || y > m) return 0;
	
	int tmp = 0;	
	if(ar[x][y] == 9) tmp = 1;
	
	return dp[x][y] = f(x+1,y,get+tmp) + f(x,y+1,get+tmp);
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &good, &wall);
	
	for(int i = 0, a, b; i < good; i++){
		scanf("%d %d", &a, &b);
		ar[a][b] = 9;
	}
	for(int i = 0, a, b; i < wall; i++){
		scanf("%d %d", &a, &b);
		ar[a][b] = 1;
	}
	
	printf("%d", f(1,1,0));
}
