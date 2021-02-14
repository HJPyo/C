#include<stdio.h>
#include<algorithm>
using namespace std;

int n, ans = 0;
struct st{ int x,y; } ar[500001];

bool cmp(st a, st b){ return a.x < b.x; }

int main()
{
	scanf("%d", &n);
	for(int i = 0, j; i < n; i++){
		scanf("%d", &j);
		ar[i] = {j,i};
	}
	
	sort(ar,ar+n,cmp);
	
	for(int i = 0; i < n; i++){
		ans = max(ans, ar[i].y-i);
	}
	
	printf("%d", ans+1);
}
