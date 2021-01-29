#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, vis[200002], ans = 0;
struct s{ int x, y; };
vector<s>v;

bool cmp(s a, s b){ return a.y < b.y; }

int f(int now, int time)
{
	vis[now] = 1;
	for(int i = now; i < n; i++){
		if(!vis[i] && v[i].x >= time){
			return f(i, v[i].y);
		}
	}
	return 1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0, j, k; i < n; i++){
		scanf("%d %d", &j, &k);
		v.push_back((s){j,k});
	}
	sort(v.begin(), v.end(), cmp);
	
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			ans += f(i,v[i].y);
		}
	}
	printf("%d", ans);
}
