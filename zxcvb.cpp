#include<stdio.h>
#include<string.h>

int t, n, ar[101], ans[101];

void f(int x, int deep)
{
	ans[x] = deep;
	int Lx = -1, Lnode = -1;
	for(int i = x-1; i >= 0 && ans[i] == -1; i--){
		if(Lx < ar[i]){
			Lx = ar[i];
			Lnode = i;
		}
	}
	if(Lnode != -1){
		f(Lnode, deep+1);
	}
	int Rx = -1, Rnode = -1;
	for(int i = x+1; i < n && ans[i] == -1; i++){
		if(Rx < ar[i]){
			Rx = ar[i];
			Rnode = i;
		}
	}
	if(Rnode != -1){
		f(Rnode, deep+1);
	}
}

int main()
{
	scanf("%d", &t);
	while(t--){
		memset(ar, 0, sizeof(ar));
		memset(ans, -1, sizeof(ans));
		
		int MAX = -1, Node = -1;
		
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &ar[i]);
			if(MAX < ar[i]){
				MAX = ar[i];
				Node = i;
			}
		}
		
		f(Node,0);
		for(int i = 0; i < n; i++){
			printf("%d ", ans[i]);
		}
		puts("");
	}
}
