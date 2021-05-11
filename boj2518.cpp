#include<stdio.h>
#include<string.h>
#include<vector>
#define INF 1999999999
using namespace std;

int n, k, dp[101][101][101][3];
vector<int>v[3];

int min(int x, int y){
	return x < y ? x : y;
}

int f(int x, int y, int z, int eat, int idx){
	if(v[0][x] == idx){
		x++;
		eat = 0;
	}
	if(v[1][y] == idx){
		y++;
		eat = 1;
	}
	if(v[2][z] == idx){
		z++;
		eat = 2;
	}
	
	printf(">>%d %d %d %d\n", x, y, z, idx);
	
	int &ret = dp[x][y][z][eat];
	if(ret != -1) return ret;
	if(v[0][x] == -1 && v[1][y] == -1 && v[2][z] == -1) return 0;
	
	int L = 1 + f(x, y, z, eat, (idx+1)%n);
	int R = 1 + f(x, y, z, eat, (idx+n-1)%n);
	
	return ret = min(L, R);
}

int main(){
	scanf("%d", &n);
	k = n/3;
	
	for(int i = 0; i < 3; i++){
		int a, b;
		scanf("%d", &a);
		for(int j = 0; j < a; j++){
			scanf("%d", &b);
			v[i].push_back((b+n-k*i) % n);
		}
		v[i].push_back(-1);
	}
	
	memset(dp, -1, sizeof(dp));
	printf("%d", f(0, 0, 0, 0, 1));
}
