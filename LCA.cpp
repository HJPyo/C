#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX 50005
using namespace std;

int n, k, MD;
int table[MAX] = {-1}, dp[MAX][505];
vector<int>v[MAX];

void f(int x, int y){
	table[x] = table[y] + 1;
	dp[x][0] = y;
	
	for(int i = 1; i <= MD; i++){
		int tmp = dp[x][i-1];
		dp[x][i] = dp[tmp][i-1];
	}
	
	for(int i = 0; i < v[x].size(); i++){
		int next = v[x][i];
		if(next != y){
			f(next,x);
		}
	}
}

int main(){
	MD = (int)floor(log2(MAX));
	
	scanf("%d", &n);
	
	for(int i = 0; i < n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	f(1,0);
	
	scanf("%d", &k);
	
	while(k--){
		int a, b;
		scanf("%d %d", &a, &b);
		
		if(table[a] != table[b]){
			if(table[a] > table[b]) swap(a,b);
			for(int i = MD; i >= 0; i--){
				if(table[a] <= table[dp[b][i]]) b = dp[b][i];
			}
		}
		
		int lca = a;
		
		if(a != b){
			for(int i = MD; i >= 0; i--){
				if(dp[a][i] != dp[b][i]){
					a = dp[a][i];
					b = dp[b][i];
				}
				lca = dp[a][i];
			}
		}
		
		printf("%d\n", lca);
	}
}
