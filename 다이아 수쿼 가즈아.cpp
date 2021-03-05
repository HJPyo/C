#include<stdio.h>
#include<vector>
#define MAX 100001
#define LL long long
#define M ((L+R)>>1)
#define cast (LL int)
using namespace std;

int n, k, Bnum;
vector<LL int>tree(MAX<<2, 0), lazy1(MAX<<2, 1), lazy2(MAX<<2, 0);

int S, E, Query;
LL int Val;

LL int MOD(LL int x)
{
	return x % cast 1000000007;
}

void propagate(int L, int R, int Node)
{
	LL int l1 = cast lazy1[Node];
	LL int l2 = cast lazy2[Node];
	LL int W = cast (R-L+1);
	if(l1 == 1 && l2 == 0) return;
	if(L < R){
		lazy1[Node<<1] = MOD(lazy1[Node<<1] * l1);
		lazy1[Node<<1|1] = MOD(lazy1[Node<<1|1] * l1);
		lazy2[Node<<1|1] = MOD(lazy2[Node<<1|1] * l1 + l2);
    }
    tree[Node] = MOD(tree[Node] * l1 + W * l2);
    lazy1[Node] = 1;
    lazy2[Node] = 0;
}

LL int update(int L, int R, int Node)
{
	propagate(L,R,Node);
	
	if(S <= L && R <= E){
		if(Query == 1){
			lazy2[Node] = MOD(lazy2[Node] + Val);
		}
		if(Query == 2){
			lazy1[Node] = MOD(lazy1[Node] * Val);
			lazy2[Node] = MOD(lazy2[Node] * Val);
		}
		if(Query == 3){
			lazy1[Node] = 0;
			lazy2[Node] = Val;
		}
		propagate(L,R,Node);
		return tree[Node];
	}
	else if(R < S || E < L){
		return tree[Node];
	}
	else{
		return tree[Node] = MOD(update(L,M,Node<<1) + update(M+1,R,Node<<1|1));
	}
}

LL int output(int L, int R, int Node)
{
	propagate(L,R,Node);
	
	if(S <= L && R <= E){
		return tree[Node];
	}
	else if(R < S || E < L){
		return 0;
	}
	else{
		return MOD(output(L,M,Node<<1) + output(M+1,R,Node<<1|1));
	}
}

int main()
{
	scanf("%d", &n);
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	for(int i = 0; i < n; i++){
		scanf("%lld", &tree[i+Bnum]);
	}
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = MOD(tree[i<<1] + tree[i<<1|1]);
	}
	
	scanf("%d", &k);
	while(k--){
		scanf("%d %d %d", &Query, &S, &E);
		
		if(Query < 4){
			scanf("%lld", &Val);
			update(1,Bnum,1);
		}
		else{
			printf("%lld\n", output(1,Bnum,1));
		}
	}
}
