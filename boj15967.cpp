#include<stdio.h>
#define M ((L+R)>>1)
#define LL long long

int n, m, o, Bnum;
LL int tree[2222222], lazy[2222222];

void prop(int L, int R, int Node)
{
	if(!lazy[Node]) return;
	
	if(Node < Bnum){
		lazy[Node<<1] += lazy[Node];
		lazy[Node<<1|1] += lazy[Node];
	}
	tree[Node] += lazy[Node] * (R-L+1);
	lazy[Node] = 0;
}

LL int hit(int L, int R, int Node, int S, int E, int Val)
{
	prop(L,R,Node);
	
	if(S <= L && R <= E){
		lazy[Node] = Val;
		prop(L,R,Node);
		return tree[Node];
	}
	else if(R < S || E < L){
		return tree[Node];
	}
	else{
		return tree[Node] = 
			hit(L,M,Node<<1,S,E,Val) +
			hit(M+1,R,Node<<1|1,S,E,Val);
	}
}

LL int hit_cnt(int L, int R, int Node, int S, int E)
{
	prop(L,R,Node);
	
	if(S <= L && R <= E){
		return tree[Node];
	}
	else if(R < S || E < L){
		return 0;
	}
	else{
		return hit_cnt(L,M,Node<<1,S,E) + hit_cnt(M+1,R,Node<<1|1,S,E);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &o);
	for(Bnum = 1; Bnum < n; Bnum<<=1);
	
	for(int i = 0; i < n; i++)
		scanf("%lld", &tree[i+Bnum]);
	
	for(int i = Bnum-1; i > 0; i--)
		tree[i] = tree[i<<1] + tree[i<<1|1];
	
	m += o;
	while(m--){
		int query, S, E, Val;
		scanf("%d %d %d", &query, &S, &E);
		
		if(query == 1){
			printf("%lld\n", hit_cnt(1,Bnum,1,S,E));
		}
		else{
			scanf("%d", &Val);
			hit(1,Bnum,1,S,E,Val);
		}
	}
}
