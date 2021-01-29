#include<stdio.h>
#define swap (z+1)%2
#define same (z+1 == ar[x] ? 1 : 0)
int n, k, ar[1001], dp[1001][31][2];

int max(int x, int y){ return x > y ? x : y; }
//x == time, y == move, z == now
int f(int x, int y, int z)
{
	if(x == n) return 0;
	if(dp[x][y][z]) return dp[x][y][z];
	if(!same){
		if(y < k){
			return dp[x][y][z] = max(1+f(x+1,y+1,swap), f(x+1,y,z));
		}
		else return dp[x][y][z] = f(x+1,y,z);
	}
	else{
		return dp[x][y][z] = 1+f(x+1,y,z);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	printf("%d", f(0,0,0));
}
