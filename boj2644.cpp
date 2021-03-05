#include<stdio.h>
#include<vector>
using namespace std;

int n, x, y, k, vis[101], ans = -1;
vector<int>len[101];

void f(int X, int Y)
{
	if(ans != -1) return;
	if(X == y){
		ans = Y;
		return;
	}
	vis[X] = 1;
	for(int i = 0; i < len[X].size(); i++){
		if(vis[len[X][i]] == 0){
			f(len[X][i],Y+1);
		}
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%d %d", &x, &y);
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		len[a].push_back(b);
		len[b].push_back(a);
	}
	f(x,0);
	printf("%d", ans);
}
