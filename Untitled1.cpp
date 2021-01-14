#include<stdio.h>
#include<vector>
#define INF 999999999
using namespace std;

int n, m, S, d[20001];
struct graph{ int D, V; };
vector<graph>v[20001];

void f(int x, int y)
{
	if(d[x] > y) d[x] = y;
	else return;
	
	for(int i = 0; i < v[x].size(); i++){
		f(v[x][i].D, v[x][i].V+y);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &S);
	for(int i = 0, a, b, c; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back((graph){b,c});
	}
	for(int i = 1; i <= 20000; i++)
	d[i] = INF;
	f(S,0);
	for(int i = 1; i <= n; i++){
		if(d[i] == INF) printf("INF\n");
		else printf("%d\n", d[i]);
	}
}
