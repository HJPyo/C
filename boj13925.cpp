#include<stdio.h>
#include<vector>
#define MOD 1000000007
#define LL long long
#define MAX 100001
#define M ((L+R)>>1)
using namespace std;

int n, m, Bnum;
LL int tree[MAX << 2];
vector<LL int>lazy1(MAX << 2, 1), lazy2(MAX << 2, 0);

void Propagate(int L, int R, int Node)
{
	int L1 = lazy1[Node];
	int L2 = lazy2[Node];
	if(L1 == 1 && L2 == 0) return;
	printf("debug");
	if(L < R){
		lazy1[Node<<1] = (L1 * lazy1[Node<<1]) % MOD;
		lazy2[Node<<1] = (L1 * lazy2[Node<<1] + L2) % MOD;
		lazy1[Node<<1|1] = (L1 * lazy1[Node<<1|1]) % MOD;
		lazy2[Node<<1|1] = (L1 * lazy2[Node<<1|1] + L2) % MOD;
	}
	tree[Node] = (L1 * tree[Node] + L2 * (R-L+1)) % MOD;;
	lazy1[Node] = 1;
	lazy2[Node] = 0;
}

LL int Update(int L, int R, int Node, int S, int E, LL int Val, int Query)
{
	printf("DEBUG");
	Propagate(L,R,Node);
	if(S <= L && R <= E){
		switch(Query){
			case 1:{
				lazy2[Node] = (lazy1[Node] * lazy2[Node] + Val) % MOD;
				break;
			}
			case 2:{
				lazy1[Node] = (lazy1[Node] * Val) % MOD;
				lazy2[Node] = (lazy2[Node] * Val) % MOD;
				break;
			}
			case 3:{
				lazy1[Node] = 0;
				lazy2[Node] = Val;
				break;
			}
		}
		Propagate(L,R,Node);
		return tree[Node];
	}
	else if(R < S || E < L){
		return tree[Node];
	}
	else{
		return tree[Node] = Update(L,M,Node<<1,S,E,Val,Query) + Update(M,R+1,Node<<1|1,S,E,Val,Query);
	}
}

int main()
{
	scanf("%d", &n);
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &tree[i + Bnum]);
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = (tree[i<<1] + tree[i<<1|1]) % MOD;
	}
	
	scanf("%d", &m);
	
	while(m--){
		int a, b, c;
		LL int d;
		scanf("%d %d %d", &a, &b, &c);
		if(a < 4){
			scanf("%lld", &d);
			Update(1,Bnum,1,b,c,d,a);
		}
	}
}
