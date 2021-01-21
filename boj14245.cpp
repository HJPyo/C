#include<stdio.h>
#define M ((L+R)>>1)

int n, k, Bnum, tree[2222222], lazy[2222222];

void propagate(int L, int R, int Node)
{
	if(!lazy[Node]) return;
	
	if(L < R){
		lazy[Node<<1] ^= lazy[Node];
		lazy[Node<<1|1] ^= lazy[Node];
	}
	tree[Node] ^= lazy[Node];
	lazy[Node] = 0;
}

int update(int L, int R, int Node, int S, int E, int Val)
{
	propagate(L,R,Node);
	
	if(S <= L && R <= E){
		lazy[Node] ^= Val;
		propagate(L,R,Node);
		return tree[Node];
	}
	else if(R < S || E < L){
		return tree[Node];
	}
	else{
		return tree[Node] = 
			update(L,M,Node<<1,S,E,Val) ^
			update(M+1,R,Node<<1|1,S,E,Val);
	}
}

int Xor(int L, int R, int Node, int T)
{
	propagate(L,R,Node);
	
	if(T <= L && R <= T){
		return tree[Node];
	}
	else if(R < T || T < L){
		return 0;
	}
	else{
		return Xor(L,M,Node<<1,T) + Xor(M+1,R,Node<<1|1,T);
	}
}

int main()
{
	scanf("%d", &n);
	for(Bnum = 1; Bnum < n; Bnum<<=1);
	//printf("%d\n", Bnum);
	
	for(int i = 0; i < n; i++)
		scanf("%d", &tree[i+Bnum]);
	
	for(int i = Bnum-1; i > 0; i--)
		tree[i] = tree[i<<1] ^ tree[i<<1|1];
	
	scanf("%d", &k);
	while(k--){
		int Query;
		scanf("%d", &Query);
		if(Query == 1){
			int s, e, Val;
			scanf("%d %d %d", &s, &e, &Val);
			update(1,Bnum,1,s+1,e+1,Val);
		}
		else{
			int t;
			scanf("%d", &t);
			printf("%d\n", Xor(1,Bnum,1,t+1));
		}
	}
}
