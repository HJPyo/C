#include<stdio.h>
#include<vector>
#include<queue>
#define INF 999999999
using namespace std;

int n, m, S;
vector<pair<int,int> >V[200001];
vector<int>D(200001, INF);
priority_queue<pair<int,int> >pQ;

void Dijk()
{
	pQ.push({0,S});
	while(!pQ.empty()){
		int Now = pQ.top().second, Dis = -pQ.top().first;
		pQ.pop();
		
		if(D[Now] < Dis) continue;
		
		for(int i = 0; i < V[Now].size(); i++){
			int Next = V[Now][i].second, NDis = Dis+V[Now][i].first;
			
			if(D[Next] > NDis){
				D[Next] = NDis;
				pQ.push({-NDis, Next});
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &S);
	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b ,&c);
		V[a].push_back({c,b});
	}
	
	D[S] = 0;
	Dijk();
	
	for(int i = 1; i <= n; i++){
		if(D[i] == INF) printf("INF\n");
		else printf("%d\n", D[i]);
	}
}
