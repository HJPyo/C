#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int boss[1000001], n, k;
vector< pair<int,int> >Q;

int Find(int x)
{
	if(boss[x] == x) return x;
	else return boss[x] = Find(boss[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if(x != y) boss[y] = x;
}

int main()
{
	for(int i = 1; i <= 100; i++){
		boss[i] = i;
	}
	
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		Q.push_back({a,b});
	}
	
	sort(Q.begin(),Q.end());
	
	for(int j = 0; j < k; j++){
		int a = Q[j].first;
		int b = Q[j].second;
		for(int i = a; i < b; i++){
			Union(i,i+1);
		}
	}
	
	int cnt = 0;
	for(int i = 1, col = 0; i <= n; i++){
		if(col != boss[i]){
			col = boss[i];
			cnt++;
		}
	}
	printf("%d", cnt);
}
