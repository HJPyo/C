#include<stdio.h>
#include<string.h>
#include<vector>
#define MOD 1000000007
using namespace std;

int n, END, dp[21][1<<21|1];
vector<int>v[21];

int gcd(int x, int y){
	return y ? gcd(y,x%y) : x;
}

int f(int x, int bit){
	if(dp[x][bit] != -1) return dp[x][bit];
	if(bit == END) return 1;
	
	int &now = dp[x][bit];
	now = 0;
	
	for(int i = 0; i < v[x].size(); i++){
		int next = v[x][i];
		if(bit & (1<<next)) continue;
		now = (now + f(next,bit|(1<<next))) % MOD;
	}
	
	return now;
}

int main(){
	memset(dp, -1, sizeof(dp));
	
	scanf("%d", &n);
	
	END = (1<<(n+1))-2;
	
	for(int i = 1; i <= n-1; i++){
		for(int j = i+1; j <= n; j++){
			if(gcd(i,j) == 1){
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
	
	printf("%d", f(1,1<<1));
	
	return 0;
}
