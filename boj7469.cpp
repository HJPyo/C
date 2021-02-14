#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;

int n, m, Bnum;
vector<int>tree[MAX<<2];

vector<int> query(int L, int R, int Node, int S, int E)
{
	if(S <= L && R <= E){
		return tree[Node];
	}
	else if(R < S || E < L){
		return vector<int>();
	}
	else{
		int M = (L+R) >> 1;
		vector<int>v1 = query(L,M,Node<<1,S,E);
		vector<int>v2 = query(M+1,R,Node<<1|1,S,E);
		v1.insert(v1.end(),v2.begin(),v2.end());
		return v1;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	for(int i = 0; i < n; i++){
		int j;
		scanf("%d", &j);
		tree[i+Bnum].push_back(j);
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i].insert(tree[i].end(), tree[i<<1].begin(), tree[i<<1].end());
		tree[i].insert(tree[i].end(), tree[i<<1|1].begin(), tree[i<<1|1].end());
	}
	
	while(m--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vector<int>tmp = query(1,Bnum,1,a,b);
		sort(tmp.begin(),tmp.end());
		for(int i = 0; i < tmp.size(); i++){
			printf("[%d] ", tmp[i]);
		}
		puts("");
		printf("%d\n", tmp[c-1]);
	}
}
