#include<stdio.h>
#include<vector>
#define IsSafe() (x>=0&&x<n&&ar[x][y]!=1&&y<m)
using namespace std;

int n, m, ar[1001][1001];
vector<vector<int> >dp(1001, vector<int>(1001,-1));

int max(int x, int y)
{
	return x > y ? x : y;
}

int f(int x, int y, int cnt)
{
	if(!IsSafe()) return -1;
	if(ar[x][y] == 9) return cnt;
	if(dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	
	cnt += (ar[x][y] == 2 ? 1:0);
	return dp[x][y] = max(max(f(x+1,y+1,cnt),f(x,y+1,cnt)),f(x-1,y+1,cnt));
}

int main()
{
	int sx, sy;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		char tmp[1005];
		scanf("%s", &tmp);
		for(int j = 0; j < m; j++){
			switch(tmp[j]){
				case 'R' :{
					ar[i][j] = 0;
					sx = i; sy = j;
					break;
				}case 'C' :{
					ar[i][j] = 2;
					break;
				}case '#' :{
					ar[i][j] = 1;
					break;
				}case 'O' :{
					ar[i][j] = 9;
					break;
				}
			}
		}
	}
	
	printf("%d", f(sx, sy, 0));
}
