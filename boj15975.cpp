#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 100001
#define LL long long
using namespace std;

int n, MAX_col = -1;
vector< pair<int,int> >dot(MAX, pair<int,int>(-1,-1));
LL int ans = 0;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		MAX_col = max(MAX_col, b);
		pair<int,int> &now = dot[b];
		if(now.first > a || now.first == -1) now.first = a;
		if(now.second < a || now.second == -1) now.second = a;
	}
	
	for(int i = 1, j = MAX_col; i <= j; i++){
		pair<int,int> &now = dot[i];
		printf(">%d %d<\n", now.first, now.second);
		if(now.first == now.second) continue;
		ans += 1 + (LL int)now.second - (LL int)now.first;
	}
	
	printf("%lld", ans);
}
