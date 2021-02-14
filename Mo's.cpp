#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int n, root;
struct Q{
	int S, E, idx;
}query[1001];

bool cmp(Q x, Q y)
{
	if(x.S / root != y.S / root) return x.S < y.S;
	else return x.E < y.E;
}

int main()
{
	scanf("%d", &n);
	root = sqrt(n);
	for(int i = 1; i <= n; i++){
		query[i].idx = i;
		scanf("%d %d", &query[i].S, &query[i].E);
	}
	
	sort(query+1, query+1+n, cmp);
	
	for(int i = 1; i <= n; i++){
		printf("{%d, %d}\n", query[i].S, query[i].E);
	}
}
