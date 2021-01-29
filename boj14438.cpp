#include<stdio.h>
#include<vector>
#include<algorithm>
#define M (L+R)/2
#define INF 1999999999
using namespace std;

int n, k, Bnum;
vector<int>tree(400004,INF);

int update(int L, int R, int Node, int T, int V)
{
	if(T <= L && R <= T)	return tree[Node] = V;
	else if(R < T || T < L)	return tree[Node];
	else return tree[Node] = min(update(L,M,Node*2,T,V), update(M+1,R,Node*2+1,T,V));
}

int query(int L, int R, int Node, int S, int E)
{
	if(S <= L && R <= E) 	return tree[Node];
	else if(R < S || E < L)	return INF;
	else return min(query(L,M,Node*2,S,E), query(M+1,R,Node*2+1,S,E));
}

int main()
{
	scanf("%d", &n);
	for(Bnum = 1; Bnum < n; Bnum*=2);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &tree[i+Bnum]);
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = min(tree[i*2], tree[i*2+1]);
	}
	
	scanf("%d", &k);
	while(k--){
		int o, x, y;
		scanf("%d %d %d", &o, &x, &y);
		if(o == 1) update(1,Bnum,1,x,y);
		else printf("%d\n", query(1,Bnum,1,x,y));
	}
}
