#include<stdio.h>
#define MAX 1000001
#define LL long long

int n, m, k;
LL int tree[MAX<<2], lazy[MAX<<2];

int Order, S, E;
LL int Val;

void propagate(int L, int R, int Node)
{
	if(lazy[Node] == 0) return;
	if(L < R){
		lazy[Node<<1] += lazy[Node];
		lazy[Node<<1|1] += lazy[Node];
	}
	tree[Node] += lazy[Node] * (R-L+1);
	lazy[Node] = 0;
}

LL int update(int L, int R, int Node)
{
	propagate(L,R,Node);
	
	if(S <= L && R <= E){
		lazy[Node] = Val;
		propagate(L,R,Node);
		return tree[Node];
	}
	else if(R < S || E < L){
		return tree[Node];
	}
	else{
		int M = (L+R) >> 1;
		return tree[Node] = 
			update(L,M,Node<<1) + 
			update(M+1,R,Node<<1|1);
	}
}

LL int query(int L, int R, int Node)
{
	propagate(L,R,Node);
	
	if(S <= L && R <= E){
		return tree[Node];
	}
	else if(R < S || E < L){
		return 0;
	}
	else{
		int M = (L+R) >> 1;
		return query(L,M,Node<<1) + query(M+1,R,Node<<1|1);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	int Bnum;
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	for(int i = 0; i < n; i++){
		scanf("%lld", &tree[i+Bnum]);
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = tree[i<<1] + tree[i<<1|1];
	}
	
	for(int i = 0; i < m+k; i++){
		scanf("%d %d %d", &Order, &S, &E);
		if(Order == 1){
			scanf("%lld", &Val);
			update(1,Bnum,1);
		}
		else{
			printf("%lld\n", query(1,Bnum,1));
		}
	}
}
