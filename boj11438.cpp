#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX 100001
using namespace std;

int n, k;
int table[MAX], dp[MAX][25];
vector<int>v[MAX];

void f(int x, int parent, int deep){
	table[x] = deep;
	dp[x][0] = parent;
	
	int tmp = parent;
	int idx = 1;
	while(tmp != 0){
		dp[x][idx] = dp[tmp][idx-1];
		tmp = dp[x][idx-1];
		idx++;
	}
	
	for(int i = 0; i < v[x].size(); i++){
		int next = v[x][i];
		if(next != parent){
			f(next,x,deep+1);
		}
	}
}

int main(){
	scanf("%d", &n);
	
	for(int i = 1; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	f(1,0,0);
	
	scanf("%d", &k);
	
	while(k--){
		int a, b;
		scanf("%d %d", &a, &b);
		
		if(table[a] != table[b]){
			if(table[a] < table[b]) swap(a,b);
			
			while(table[a] != table[b]){
				a = dp[a][0];
			}
		}
		
		if(a != b){
			int idx = 0;
			while(a != b){
				a = dp[a][idx];
				b = dp[b][idx];
				idx++;
			}
		}
		
		printf("%d\n", a);
	}
}
