#include<stdio.h>
#define M (L+R)/2

int n, k, Bnum, tree[444444] = {};
int S, E;

int query(int L, int R, int Node)
{
	if(R < S || E < L) return 0;
	else if(S <= L && R <= E) return tree[Node];
	else return query(L,M,Node<<1) + query(M+1,R,Node<<1|1);
}

int main()
{
	scanf("%d %d", &n, &k);
	for(Bnum = 1; Bnum < n; Bnum*=2);
	
	for(int i = 0; i < n; i++)
		scanf("%d", &tree[i+Bnum]);
	
	for(int i = Bnum-1; i > 0; i--)
		tree[i] = tree[i<<1] + tree[i<<1|1];
	
	while(k--){
		scanf("%d %d", &S, &E);
		printf("%d\n", query(1,Bnum,1));
	}
}
