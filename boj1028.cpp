#include<stdio.h>

int n, m, ar[777][777], dp[777][777];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int max(int x, int y)
{
	return x > y ? x : y;
}

int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	scanf("%d %d", &n, &m);
	
	int flag = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &ar[i][j]);
			flag = dp[i][j] = ar[i][j];
		}
	}
	
	if(flag == 0){
		printf("0");
		return 0;
	}
	
	int MAX, ans = 0;
	
	while(1){
		MAX = 0;
		for(int i = 1; i < n-1; i++){
			for(int j = 1; j < m-1; j++){
				int now = 777;
				for(int k = 0; k < 4; k++){
					int nx = i+dx[k];
					int ny = j+dy[k];
					now = min(now,dp[nx][ny]);
				}
				dp[i][j] = now+1;
				MAX = max(MAX,dp[i][j]);
			}
		}
		if(MAX == ans) break;
		ans = MAX;
	}
	
	printf("%d", ans);
}
