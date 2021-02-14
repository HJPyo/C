#include<stdio.h>
#include<vector>
#define INF 1999999999
using namespace std;

int t;

int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	scanf("%d", &t);
	while(t--){
		int n, m, o, flag = 0;
		vector< pair<int,int> >len[505];
		vector< vector<int> >ar(505,vector<int>(505,INF));
		scanf("%d %d %d", &n, &m, &o);
		for(int i = 0; i < m; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if(b == 1) b = n+1;
			len[a].push_back({b,c});
		}
		for(int i = 0; i < o; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if(b == 1) b = n+1; c *= -1;
			len[a].push_back({b,c});
		}
		n++;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < len[i].size(); j++){
				int next = len[i][j].first;
				int dist = len[i][j].second;
				ar[i][next] = min(ar[i][next],dist);
			}
		}
		for(int edge = 1; edge <= n; edge++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(i == j) continue;
					int now = ar[i][j], next = ar[i][edge]+ar[edge][j];
					if(now > next){
						ar[i][j] = next;
						if(edge == n){
							flag = 1;
							goto END;
						}
					}
				}
			}
		}
		END:
		printf("%s\n", flag ? "NO" : "YES");
	}
}
