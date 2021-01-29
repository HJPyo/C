#include<stdio.h>
#include<vector>
#define MAX 100001
#define INF 1999999999
using namespace std;

int min(int x, int y){ return x < y ? x : y; }
int max(int x, int y){ return x > y ? x : y; }

int query(int L, int R, int Node, int S, int E, vector<int> &tree, int Val)
{
	int M = (L+R)>>1;
	
	if(S <= L && R <= E)	return tree[Node];
	else if(R < S || E < L)	return -INF * Val;
	else return Val * max(Val * query(L,M,Node<<1,S,E,tree,Val), Val * query(M+1,R,Node<<1|1,S,E,tree,Val));
}

int main()
{
	int n, k, Bnum;
	vector<int>Min(MAX*4, INF);
	vector<int>Max(MAX*4,-INF);
	
	scanf("%d %d", &n, &k);
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	for(int i = 0, j; i < n; i++){
		scanf("%d", &j);
		Min[i+Bnum] = Max[i+Bnum] = j;
	}
	
	for(int i = Bnum-1; i > 0; i--){
		Min[i] = min(Min[i<<1], Min[i<<1|1]);
		Max[i] = max(Max[i<<1], Max[i<<1|1]);
	}
	
	while(k--){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d %d\n", query(1,Bnum,1,s,e,Min,-1), query(1,Bnum,1,s,e,Max,1));
	}
}
