#include<stdio.h>
#define MAX 100001

int n, k, Bnum, tree[MAX << 2], cnt = 0;

int query(int L, int R, int Node, int S, int E)
{
	if(S <= L && R <= E){
		return tree[Node];
	}
	else if(R < S || E < L){
		return 0;
	}
	else{
		int M = (L+R) >> 1;
		return query(L,M,Node<<1,S,E) + query(M+1,R,Node<<1|1,S,E);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &tree[i+Bnum]);
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = tree[i<<1] + tree[i<<1|1];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(query(1,Bnum,1,i,j) == k) cnt++;
		}
	}
	
	printf("%d", cnt);
}
