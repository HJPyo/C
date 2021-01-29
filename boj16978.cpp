#include<stdio.h>
#include<algorithm>
#define M (L+R)/2
#define LL long long
using namespace std;

int n, k, Bnum;
LL int tree[400004];
int query1_cnt = 1, query2_cnt = 0;
struct q1{ LL int t, val; } query1[100001];
struct q2{ LL int order, query, s, e, Ans; } query2[100001];

bool order_cmp(q2 x, q2 y) { return x.order < y.order; }
bool query_cmp(q2 x, q2 y) { return x.query < y.query; }

LL int update(int L, int R, int Node, int T, LL int Val)
{
	if(T <= L && R <= T){
		return tree[Node] = Val;
	}
	else if(R < T || T < L){
		return tree[Node];
	}
	else{
		return tree[Node] = update(L,M,Node<<1,T,Val) + update(M+1,R,Node<<1|1,T,Val);
	}
}

LL int ans(int L, int R, int Node, int S, int E)
{
	if(S <= L && R <= E){
		return tree[Node];
	}
	else if(R < S || E < L){
		return 0;
	}
	else{
		return ans(L,M,Node<<1,S,E) + ans(M+1,R,Node<<1|1,S,E);
	}
}

int main()
{
	scanf("%d", &n);
	for(Bnum = 1; Bnum < n; Bnum<<=1);
	
	for(int i = 0; i < n; i++){
		scanf("%lld", &tree[i+Bnum]);
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = tree[i<<1] + tree[i<<1|1];
	}
	
	scanf("%d", &k);
	while(k--){
		int query, t, q, s, e;
		LL int val;
		scanf("%d", &query);
		if(query == 1){
			scanf("%d %lld", &t, &val);
			query1[query1_cnt++] = {t, val};
		}
		else{
			scanf("%d %d %d", &q, &s, &e);
			query2[query2_cnt++] = {query2_cnt, q, s, e, 0};
		}
	}
	
	sort(query2, query2+query2_cnt, query_cmp);
	
	for(int i = 0, q1 = 0; i < query2_cnt; i++){
		if(q1 < query2[i].query){
			q1++;
			update(1,Bnum,1,query1[q1].t,query1[q1].val);
		}
		query2[i].Ans = ans(1,Bnum,1,query2[i].s,query2[i].e);
	}
	
	sort(query2, query2+query2_cnt, order_cmp);
	
	for(int i = 0; i < query2_cnt; i++){
		printf("%lld\n", query2[i].Ans);
	}
}
