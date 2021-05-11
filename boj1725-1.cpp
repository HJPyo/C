#include<stdio.h>
#include<string.h>
#define LL long long int
#define MAX 100005

int n;
LL ar[MAX], tree[MAX<<2];

LL max(LL x, LL y){
	return x > y ? x : y;
}

int init(int L, int R, int Node){
	if(L == R){
		tree[Node] = L;
		return tree[Node];
	}
	
	int M = (L+R) >> 1;
	int Lnode = init(L, M, Node<<1);
	int Rnode = init(M+1, R, Node<<1|1);
	
	if(ar[Lnode] < ar[Rnode]){
		tree[Node] = Lnode;
	}
	else{
		tree[Node] = Rnode;
	}
	
	return tree[Node];
}

int query(int L, int R, int Node, int S, int E){
	if(S <= L && R <= E){
		return tree[Node];
	}
	else if(E < L || R < S){
		return -1;
	}
	else{
		int M = (L+R) >> 1;
		int Lnode = query(L, M, Node<<1, S, E);
		int Rnode = query(M+1, R, Node<<1|1, S, E);
		
		if(Lnode == -1) return Rnode;
		if(Rnode == -1) return Lnode;
		
		if(ar[Lnode] < ar[Rnode]) return Lnode;
		else return Rnode;
	}
}

LL ans(int S, int E){
	int idx = query(0, n-1, 1, S, E);
	LL sex = (LL) (E - S + 1) * ar[idx];
	
	if(S <= idx-1){
		sex = max(sex, ans(S, idx-1));
	}
	if(idx+1 <= E){
		sex = max(sex, ans(idx+1, E));
	}
	
	return sex;
}

int main(){
	while(true){
		scanf("%d", &n);
		
		if(n == 0) break;
		
		for(int i = 0; i < n; i++){
			scanf("%lld", &ar[i]);
		}
		
		init(0, n-1, 1);
		
		printf("%lld\n", ans(0, n-1));
		
		memset(ar, 0, sizeof(ar));
		memset(tree, 0, sizeof(tree));
	}
	
	return 0;
}
