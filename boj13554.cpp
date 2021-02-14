#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;

int n, m, Bnum, last_ans = 0;
vector<int>tree[MAX<<2];

int Query(int L, int R, int Node, int S, int E, int Val)
{
	if(S <= L && R <= E){
		return tree[Node].end() - upper_bound(tree[Node].begin(), tree[Node].end(), Val);
	}
	else if(R < S || E < L){
		return 0;
	}
	else{
		int M = (L+R) >> 1;
		return Query(L,M,Node<<1,S,E,Val) + Query(M+1,R,Node<<1|1,S,E,Val);
	}
}

int main()
{
	scanf("%d", &n);
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	for(int i = 0; i < n; i++){
		int j;
		scanf("%d", &j);
		tree[i+Bnum].push_back(j);
	}
	
	for(int i = Bnum-1; i > 0; i--){
		int ptr1 = 0;
		int ptr2 = 0;
		int Ltree = tree[i<<1].size();
		int Rtree = tree[i<<1|1].size();
		tree[i].push_back(0);
		while(ptr1 < Ltree || ptr2 < Rtree){
			if(ptr1 == Ltree){
				tree[i].push_back(tree[i<<1|1][ptr2++]);
			}
			else if(ptr2 == Rtree){
				tree[i].push_back(tree[i<<1][ptr1++]);
			}
			else if(tree[i<<1][ptr1] < tree[i<<1|1][ptr2]){
				tree[i].push_back(tree[i<<1][ptr1++]);
			}
			else{
				tree[i].push_back(tree[i<<1|1][ptr2++]);
			}
		}
	}
	
	scanf("%d", &m);
	
	while(m--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a ^= last_ans;
		b ^= last_ans;
		c ^= last_ans;
		last_ans = Query(1,Bnum,1,a,b,c);
		printf("%d\n", last_ans);
	}
}
