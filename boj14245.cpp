#include<stdio.h>
#define M (L+R)/2

int n, m, o, tree[2222222], lazy[2222222];

void prop(int L, int R, int N)
{
	if(!lazy[N]) return;
	if(L < R){
		lazy[N<<1] ^= lazy[N];
		lazy[N<<1|1] ^= lazy[N];
	}
	if((R-L+1) & 1){
		tree[N] ^= lazy[N];
	}
	lazy[N] = 0;
}

int update(int L, int R, int N, int S, int E, int V)
{
	prop(L, R, N);
	if(L <= S && E <= R){
		lazy[N] = V;
		prop(L, R, N);
		return tree[N];
	}
	else if(E < L || R < S){
		return tree[N];
	}
	else{
		return tree[N] = 
			update(L,M,N<<1,S,E,V) +
			update(M+1,R,N<<1|1,S,E,V);
	}
}

int query(int L, int R, int N, int T)
{
	prop(L, R, N);
	if(T < L || R < T){
		return 0;
	}
	else if(L < R){
		return query(L,M,N<<1,T) + query(M+1,R,N<<1|1,T);
	}
	else{
		return tree[N];
	}
}

int main()
{
	scanf("%d", &n);
	for(o=1; o<n; o*=2);
	for(int i = 0; i < n; i++)
	scanf("%d", &tree[i+o]);
	scanf("%d", &m);
	while(m--){
		int a;
		scanf("%d", &a);
		if(a==1){
			int l, r, v;
			scanf("%d %d %d", &l, &r, &v);
			update(1,o,1,l+1,r+1,v);
		}
		if(a==2){
			int t;
			scanf("%d", &t);
			printf("%d\n", query(1,o,1,t+1));
		}
	}
}
