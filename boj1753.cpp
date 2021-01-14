#include<stdio.h>
#include<vector>
#define INF 1999999999
using namespace std;

int n, m, S, d[20001];
struct graph{ short dir, val; };
vector<graph>v[20001];

int Min(int x, int y)
{
	return x < y ? x : y;
}

void f(int x, int y)
{
	d[x] = Min(d[x], y);
	
	for(int i = 0; i < v[x].size(); i++){
		f(v[x][i].dir, y+v[x][i].val);
	}
}

int main()
{
	for(int i = 1; i <= 20000; i++)
		d[i] = INF;
	scanf("%d %d %d", &n, &m, &S);
	for(int i = 0; i < m; i++){
		int v1, v2, v3;
		scanf("%d %d %d", &v1, &v2, &v3);
		v[v1].push_back((graph){v2,v3});
	}
	f(S,0);
	for(int i = 1; i <= n; i++){
		if(d[i] != INF) printf("%d\n", d[i]);
		else printf("INF\n");
	}
}
