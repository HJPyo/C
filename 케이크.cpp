#include<iostream>
#define MAX 100001
using namespace std;

int n, k, Bnum, tree[MAX<<2], lazy[MAX<<2];
int S, E, Val;

void propagate(int L, int R, int Node){
	if(!lazy[Node]) return;
	if(L < R){
		lazy[Node<<1] += lazy[Node];
		lazy[Node<<1|1] += lazy[Node];
	}
	tree[Node] += lazy[Node] * (R-L+1);
	lazy[Node] = 0;
}

int update(int L, int R, int Node){
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
		return tree[Node] = update(L,M,Node<<1) + update(M+1,R,Node<<1|1);
	}
}

int query(int L, int R, int Node){
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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	for(int i = 0; i > n; i++){
		cin >> tree[i+Bnum];
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = tree[i<<1] + tree[i<<1|1];
	}
	
	while(k--){
		cin >> S >> E >> Val;
		update(1,Bnum,1);
	}
	
	for(int i = 1; i <= n; i++){
		S = E = i;
		cout << query(1,Bnum,1) << ' ';
	}
}
