#include<stdio.h>
#define MAX 100001

int n, k, Bnum, tree[MAX<<2], lazy[MAX<<2];
int Query, S, E;

void propagate(int W, int Node)
{
	if(!lazy[Node]) return;
	if(Node < Bnum){
		lazy[Node<<1] += lazy[Node];
		lazy[Node<<1|1] += lazy[Node] + (W>>1);
	}
	tree[Node] += ((lazy[Node]<<1)+W-1) * (W>>1);
	lazy[Node] = 0;
}

int update(int L, int R, int Node)
{
	propagate(R-L+1,Node);
	
	if(S <= L && R <= E){
		lazy[Node] = L-S+1;
		propagate(R-L+1,Node);
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

int output(int L, int R, int Node)
{
	propagate(R-L+1,Node);
	
	if(S <= L && R <= S){
		return tree[Node];
	}
	else if(R < S || S < L){
		return 0;
	}
	else{
		int M = (L+R) >> 1;
		return output(L,M,Node<<1) + output(M+1,R,Node<<1|1);
	}
}

int main()
{
	scanf("%d", &n);
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &tree[i+Bnum]);
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = tree[i<<1] + tree[i<<1|1];
	}
	
	scanf("%d", &k);
	while(k--){
		scanf("%d %d", &Query, &S);
		if(Query == 1){
			scanf("%d", &E);
			update(1,Bnum,1);
		}
		else{
			printf("%d\n", output(1,Bnum,1));
		}
	}
}
