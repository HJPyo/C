#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

int n, m, k;
int ar[55][55], tmp[55][55];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
vector<pair<int,int>>koosaga;

int main(){
	memset(ar, -1, sizeof(ar));
	
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &ar[i][j]);
			if(ar[i][j] == -1){
				koosaga.push_back({i, j});
			}
		}
	}
	
	for(int time = 1; time <= k; time++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(ar[i][j] > 0){
					int go = ar[i][j] / 5;
					int cnt = 0;
					
					for(int d = 0; d < 4; d++){
						int nx = i + dx[d];
						int ny = j + dy[d];
						
						if(ar[nx][ny] != -1){
							cnt++;
							tmp[nx][ny] += go;
						} 
					}
					
					ar[i][j] -= (cnt * go);
				}
			}
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				ar[i][j] += tmp[i][j];
				tmp[i][j] = 0;
			}
		}
		
		int kx = koosaga[0].first, ky = koosaga[0].second;
		
		for(int i = kx; i > 1; i--){
			ar[i][1] = ar[i-1][1];
			ar[i-1][1] = 0;
		}
		
		for(int i = 1; i < m; i++){
			ar[1][i] = ar[1][i+1];
			ar[1][i+1] = 0;
		}
		
		for(int i = 1; i < kx; i++){
			ar[i][m] = ar[i+1][m];
			ar[i+1][m] = 0;
		}
		
		for(int i = m; i > 2; i--){
			ar[kx][i] = ar[kx][i-1];
			ar[kx][i-1] = 0;
		}
		
		ar[kx][ky] = -1;
		
		kx = koosaga[1].first;
		ky = koosaga[1].second;
		
		for(int i = kx; i < n; i++){
			ar[i][1] = ar[i+1][1];
			ar[i+1][1] = 0;
		}
		
		for(int i = 1; i < m; i++){
			ar[n][i] = ar[n][i+1];
			ar[n][i+1] = 0;
		}
		
		for(int i = n; i > kx; i--){
			ar[i][m] = ar[i-1][m];
			ar[i-1][m] = 0;
		}
		
		for(int i = m; i > 2; i--){
			ar[kx][i] = ar[kx][i-1];
			ar[kx][i-1] = 0;
		}
		
		ar[kx][ky] = -1;
	}
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(ar[i][j] != -1){
				ans += ar[i][j];
			}
		}
	}
	
	printf("%d", ans);
}
