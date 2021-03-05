#include<stdio.h>
#include<vector>
#define MAX 5000005
#define INF 1999999999
using namespace std;

int n, k, Bnum;
vector<int>tree(MAX<<2,INF);

int max(int x, int y)
{
	return x > y ? x : y;
}

int min(int x, int y)
{
	return x < y ? x : y;
}

int query(int L, int R, int Node, int S, int E)
{
	if(S <= L && R <= E){
		return tree[Node];
	}
	else if(R < S || E < L){
		return INF;
	}
	else{
		int M = (L+R) >> 1;
		return min(query(L,M,Node<<1,S,E), query(M+1,R,Node<<1|1,S,E));
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &tree[i+Bnum]);
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = min(tree[i<<1], tree[i<<1|1]);
	}
	
	for(int i = 1; i <= n; i++){
		printf("%d ", query(1,Bnum,1,max(1,i-k+1),i));
	}
}
