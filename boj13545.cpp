#include<stdio.h>
#include<math.h>
#include<algorithm>
#define MAX 100001
using namespace std;

int n, m, RT, ar[MAX];

struct Q{
	int S, E, idx, Vis[MAX], cnt;
}query[MAX];

bool cmp(Q x, Q y)
{
	if(x.S/RT != y.S/RT) return x.S < y.S;
	else return x.E < y.E;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &query[i].S, &query[i].E);
		query[i].idx = i;
	}
	sort(query+1, query+1+m, cmp);
}
