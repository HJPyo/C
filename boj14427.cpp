#include<stdio.h>
#include<vector>
#include<algorithm>
#define M (L+R)/2
#define INF 1999999999
using namespace std;

int n, k, Bnum, index[444444];
vector<int>tree(444444,INF);

int update(int L, int R, int Node, int T, int Val)
{
	if(L <= T && T <= R){
		return tree[Node] = Val;
	}
	else if(T < R && T < L){
		return tree[Node];
	}
	else{
		return tree[Node] = min(update(L,M,Node<<1,T,Val), update(M+1,R,Node<<1|1,T,Val));
	}
}

int main()
{
	scanf("%d", &n);
	for(Bnum = 1; Bnum < n; Bnum<<=1);
	
	int m = INF;
	for(int i = 0; i < n; i++){
		scanf("%d", &tree[i+Bnum]);
		if(m < tree[i+Bnum]) index[1] = tree[i+Bnum];
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = min(tree[i<<1], tree[i<<1|1]);
	}
	
	scanf("%d", &k);
	while(k--){
		int query, t, v;
		scanf("%d", &query);
		if(query == 1){
			scanf("%d %d", &t, &v);
			update(1,Bnum,1,t,v);
		}
		else{
			printf("%d\n", index[1]);
		}
	}
}
