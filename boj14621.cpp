#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, boss[1001];
char col[1001];
vector<pair<int,pair<int,int>>>v;

int Find(int x)
{
	if(boss[x] == x) return x;
	else return boss[x] = Find(boss[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if(x < y) boss[y] = x;
	else boss[x] = y;
}

int main()
{
	scanf("%d %d", &n, &k);
	
	char tmp[2002];
	cin.getline(tmp, 2002);
	
	for(int i = 0; i < n*2; i++){
		printf("%c", tmp[i]);
	}
	
	for(int i = 1; i <= n; i++){
		col[i] = tmp[(i-1) * 2];
	}
	
	for(int i = 0; i < k; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(col[a] != col[b]) v.push_back({c,{a,b}});
	}
	
	sort(v.begin(), v.end());
	
	int ans = 0;
	
	for(int i = 0, cnt = 0; cnt < n-1 && i < v.size(); i++){
		int len = v[i].first;
		int L = v[i].second.first;
		int R = v[i].second.second;
		printf(">>%d %d %d\n", len, L, R);
		if(Find(R) != Find(L)){
			Union(L,R);
			ans += len;
			cnt++;
		}
	}
	
	printf("%d", ans);
}
