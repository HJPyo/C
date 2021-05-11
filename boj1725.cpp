#include<stdio.h>
#define LL long long int
#define MAX 100005
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)

struct seg{
	int idx;
	LL val;
}tree[MAX << 2];

int n;
LL ar[MAX << 2];

seg query(int L, int R, int Node, int S, int E){
	if(S <= L && R <= E){
		return tree[Node];
	}
	else if(R < S || E < L){
		return {-1, -1};
	}
	else{
		int M = (L+R) >> 1;
		seg Lnode = query(L, M, Node<<1, S, E);
		seg Rnode = query(M+1, R, Node<<1|1, S, E);
		if(Lnode.idx == -1) return Rnode;
		if(Rnode.idx == -1) return Lnode;
		return Lnode.idx < Rnode.idx ? Lnode : Rnode;
	}
}

LL ans(int S, int E){
	seg tmp = query(0, n-1, 1, S, E);
	int idx = tmp.idx;
	LL sex = (E - S + 1) * ar[idx];
	printf(">>%d %d %d\n", S, E, idx);
	if(S < idx){
		sex = max(sex, ans(S, idx-1));
	}
	if(idx < E){
		sex = max(sex, ans(idx+1, E));
	}
	
	return sex;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%lld", &ar[i]);
		tree[i+n] = {i, ar[i]};
	}
	
	for(int i = n-1; i > 0; i--){
		if(tree[i<<1].val < tree[i<<1|1].val){
			tree[i] = tree[i<<1];
		}
		else{
			tree[i] = tree[i<<1|1];
		}
	}
	
	printf("%lld", ans(0, n-1));
	
	return 0;
}
