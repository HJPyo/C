#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int t, n, ans[101] = {};

void dfs(int *tree, int x, int deep)
{
	ans[x] = deep;
	int Lmax = -1, Lnode = -1;
	for(int i = x-1; x >= 0; i--){
		if(Lmax < tree[i]){
			Lmax = tree[i];
			Lnode = i;
		}
	}
	if(Lmax != -1){
		dfs(tree,Lnode,deep+1);
	}
	int Rmax = -1, Rnode = -1;
	for(int i = x+1; x < n; i++){
		if(Rmax < tree[i]){
			Rmax = tree[i];
			Rnode = i;
		}
	}
	if(Rmax != -1){
		dfs(tree,Rnode,deep+1);
	}
}

int main()
{
	scanf("%d", &t);
	
	while(t--){
		memset(ans, 0, sizeof(ans));
		int ar[101], root = -1, MAX = -1;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &ar[i]);
			if(MAX < ar[i]){
				MAX = ar[i];
				root = i;
			}
		}
		dfs(ar,root,0);
		for(int i = 0; i < n; i++){
			printf("%d ", ans[i]);
		}
		puts("");
	}
}
