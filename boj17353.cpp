#include<stdio.h>
#define MAX 100001
#define LL long long
#define M ((L+R)>>1)

int n, k, Bnum;
LL int tmp[MAX], ar[MAX], tree[MAX<<2], lazy[MAX<<2];

LL init(int L, int R, int Node)
{
	if(L < R){
		return tree[Node] = 
			init(L,M,Node<<1) + 
			init(M+1,R,Node<<1|1);
	}
	else{
		return tree[Node] = ar[L];
	}
}

void propagate(int L, int R, int Node)
{
	if(lazy[Node] == 0) return;
	if(L < R){
		lazy[Node<<1] += lazy[Node];
		lazy[Node<<1|1] += lazy[Node];
	}
	tree[Node] += (R-L+1) * lazy[Node];
	lazy[Node] = 0;
}

LL int update(int L, int R, int Node, int S, int E, int V)
{
	propagate(L,R,Node);
	
	if(S <= L && R <= E){
		lazy[Node] = V;
		propagate(L,R,Node);
		return tree[Node];
	}
	else if(R < S || E < L){
		return tree[Node];
	}
	else{
		return tree[Node] = 
			update(L,M,Node<<1,S,E,V) +
			update(M+1,R,Node<<1|1,S,E,V);
	}
}

LL int query(int L, int R, int Node, int S, int E)
{
	propagate(L,R,Node);
	
	if(S <= L && R <= E){
		return tree[Node];
	}
	else if(R < S || E < L){
		return 0;
	}
	else{
		return query(L,M,Node<<1,S,E) + query(M+1,R,Node<<1|1,S,E);
	}
}

int main()
{
	scanf("%d", &n);
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	for(int i = 1; i <= n; i++){
		scanf("%lld", &tmp[i]);
		ar[i] = tmp[i] - tmp[i-1];
	}
	
	init(1,Bnum,1);
	
	int a, b, c;
	scanf("%d", &k);
	while(k--){
		scanf("%d %d", &a, &b);
		if(a == 1){
			scanf("%d", &c);
			update(1,Bnum,1,b,c,1);
			update(1,Bnum,1,c+1,c+1,-(c-b+1));
		}
		else{
			printf("%lld\n", query(1,Bnum,1,1,b));
		}
	}
}
