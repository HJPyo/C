#include<stdio.h>

int n, k, tree[55][55], st[55], vis[55], cnt = 0;

void f(int x)
{
	vis[x] = 1;
	
	int tmp = 0;
	
	for(int i = 0; i < n; i++){
		if(tree[x][i] && !vis[i] && i != k){
			f(i);
			tmp++;
		}
	}
	
	if(tmp == 0) cnt++;
}

int main()
{
	scanf("%d", &n);
	
	for(int i = 0, j; i < n; i++){
		scanf("%d", &j);
		
		if(j == -1){
			st[i] = 1;
		}
		else{
			tree[i][j] = 1;
			tree[j][i] = 1;
		}
	}
	
	scanf("%d", &k);
	
	for(int i = 0; i < n; i++){
		if(st[i] && i != k) f(i);
	}
	
	printf("%d", cnt);
	
	return 0;
}
