#include<cstdio>

int n, k, con[101][101], vis[101];

int f(int x){
	int tmp = 1;
	vis[x] = 1;
	for(int i = 1; i <= n; i++){
		if(con[x][i] && !vis[i]){
			tmp += f(i);
		}
	}
	return tmp;
}

int main(){
	scanf("%d %d", &n, &k);
	
	while(k--){
		int a, b;
		scanf("%d %d", &a, &b);
		con[a][b] = con[b][a] = 1;
	}
	
	printf("%d", f(1)-1);
}
