#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, table[10001], sum = 0;
vector< pair<int, pair<int,int> > >len;

int parent(int x)
{
	if(table[x] == x) return x;
	return table[x] = parent(table[x]);
}

void UF(int x, int y)
{
	x = parent(x);
	y = parent(y);
	if(x < y) table[y] = x;
	else table[x] = y;
}

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= n; i++){
		table[i] = i;
	}
	
	for(int i = 0; i < k; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a > b) swap(a,b);
		len.push_back({c,{a,b}});
	}
	
	sort(len.begin(),len.end());
	
	for(int i = 0, cnt = 0; cnt < n-1; i++){
		int dist = len[i].first;
		int now = len[i].second.first;
		int next = len[i].second.second;
		if(parent(now) != parent(next)){
			UF(now,next);
			sum += dist;
			cnt++;
		}
	}
	printf("%d\n", sum);
}
