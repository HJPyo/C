#include<stdio.h>
#include<vector>
#define MAX 100
#define INF 999999999
using namespace std;

int n, k;
vector< pair<int,int> >bus[MAX+1];
vector< vector<int> >ar(MAX+1,vector<int>(MAX+1,INF));

int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		bus[a].push_back({b,c});
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < bus[i].size(); j++){
			int next = bus[i][j].first;
			int dist = bus[i][j].second;
			ar[i][next] = min(ar[i][next], dist);
		}
	}
	
	for(int edge = 1; edge <= n; edge++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j || i == edge || j == edge) continue;
				ar[i][j] = min(ar[i][j], ar[i][edge] + ar[edge][j]);
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", ar[i][j] == INF ? 0 : ar[i][j]);
		}
		puts("");
	}
}
