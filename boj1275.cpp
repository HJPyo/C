#include<stdio.h>
#define M (L+R)/2
#define LL long long

int n, k, Bnum;
LL int tree[444444];

void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

LL int update(int L, int R, int Node, int T, LL int V)
{
	if(T <= L && R <= T){
		return tree[Node] = V;
	}
	else if(R < T || T < L){
		return tree[Node];
	}
	else{
		return tree[Node] = 
			update(L,M,Node<<1,T,V) +
			update(M+1,R,Node<<1|1,T,V);
	}
}

LL int query(int L, int R, int Node, int S, int E)
{
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
	scanf("%d %d", &n, &k);
	for(Bnum = 1; Bnum < n; Bnum<<=1);
	
	for(int i = 0; i < n; i++){
		scanf("%lld", &tree[i+Bnum]);
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = tree[i<<1] + tree[i<<1|1];
	}
	
	int S, E;
	while(k--){
		scanf("%d %d", &S, &E);
		if(S > E) swap(S, E);
		printf("%lld\n", query(1,Bnum,1,S,E));
		
		scanf("%d %d", &S, &E);
		update(1,Bnum,1,S,E);
	}
}
