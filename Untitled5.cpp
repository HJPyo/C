#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, Bnum, tree[400004];
struct asdf{ int as,df; };
struct qwer{ int q,w,e,r,t; };
vector<asdf>q1(1,{0,0});
vector<qwer>q2;

bool cmp1(qwer x, qwer y){ return x.w < y.w; }
bool cmp2(qwer x, qwer y){ return x.q < y.q; }

int chn(int L,int R,int N,int T,int V)
{
	int M = (L+R)/2;
	if(T <= L && R <= T) return tree[N] = V;
	else if(R < T || T < L) return tree[N];
	else return tree[N] = chn(L,M,N*2,T,V) + chn(M+1,R,N*2+1,T,V);
}

int sum(int L,int R,int N,int S,int E)
{
	int M = (L+R)/2;
	if(S <= L && R <= E) return tree[N];
	else if(R < S || E < L) return 0;
	else return sum(L,M,N*2,S,E) + sum(M+1,R,N*2+1,S,E);
}

int main()
{
	scanf("%d", &n);
	for(Bnum = 1; Bnum < n; Bnum*=2);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &tree[Bnum+i]);
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = tree[i<<1] + tree[i<<1|1];
	}
	
	scanf("%d", &k);
	while(k--){
		int A,B,C,D;
		scanf("%d", &A);
		if(A == 1){
			scanf("%d %d", &B, &C);
			q1.push_back({B,C});
		}
		else{
			scanf("%d %d %d", &B, &C, &D);
			q2.push_back({q2.size(),B,C,D,0});
		}
	}
	
	sort(q2.begin(), q2.end(), cmp1);
	
	for(int i = 0, j = 0; i < q2.size(); i++){
		if(j < q2[i].w){
			j++;
			chn(1,Bnum,1,q1[j].as,q1[j].df);
		}
		q2[i].t = sum(1,Bnum,1,q2[i].e,q2[i].r);
	}
	
	sort(q2.begin(), q2.end(), cmp2);
	
	for(int i = 0; i < q2.size(); i++){
		printf("%d\n", q2[i].t);
	}
}
