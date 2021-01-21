#include<stdio.h>
#define M (L+R)/2

int n, k, Bnum, ans, tree[4099][4099], treetree[4099];
int query, x1, y1, x2, y2, V;

int update(int L, int R, int Node, int X)
{
	if(R < y1 || y1 < L){
		return tree[X][Node];
	}
	else if(y1 <= L && R <= y1){
		return tree[X][Node] = V;
	}
	else{
		return tree[X][Node] = update(L,M,Node<<1,X) + update(M+1,R,Node<<1|1,X);
	}
}

int sum(int L, int R, int Node, int X)
{
	if(R < y1 || y2 < L){
		return 0;
	}
	else if(y1 <= L && R <= y2){
		return tree[X][Node];
	}
	else{
		return sum(L,M,Node<<1,X) + sum(M+1,R,Node<<1|1,X);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for(Bnum = 1; Bnum < n; Bnum*=2);
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n; j++)
			scanf("%d", &tree[i][j+Bnum]);
		
		for(int j = Bnum-1; j > 0; j--)
			tree[i][j] = tree[i][j<<1] + tree[i][j<<1|1];
	}
	
	while(k--){
		scanf("%d", &query);
		if(query){
			ans = 0;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			for(int i = x1; i <= x2; i++)
				ans += sum(1,Bnum,1,i);
			printf("%d\n", ans);
		}
		else{
			scanf("%d %d %d", &x1, &y1, &V);
			update(1,Bnum,1,x1);
		}
	}
}
