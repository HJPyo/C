#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int n, m, ar[101][101], air[101][101], chz[101][101];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

bool chk()
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(ar[i][j] == 1) return true;
		}
	}
	return false;
}

bool IsSafe(int x, int y)
{
	return 0 <= x && 0 <= y && x < n && y < m;
}

void IsAir(int x, int y)
{
	air[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(air[nx][ny] == 0 && ar[nx][ny] == 0 && IsSafe(nx,ny)){
			IsAir(nx,ny);
		}
	}
}

int main()
{
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> ar[i][j];
		}
	}
	
	int time = 0, chz_cnt;
	
	while(chk()){
		memset(air, 0, sizeof(air));
		memset(chz, 0, sizeof(chz));
		chz_cnt = 0;
		IsAir(0,0);
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(ar[i][j] == 1){
					for(int k = 0; k < 4; k++){
						int ni = i+dx[k];
						int nj = j+dy[k];
						if(air[ni][nj] == 1){
							chz[i][j]++;
						}
					}
				}
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(chz[i][j] >= 1){
					ar[i][j] = 0;
					chz_cnt++;
				}
			}
		}
		
		time++;
	}
	
	cout << time << '\n' << chz_cnt;
}
