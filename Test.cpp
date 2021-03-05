#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int t;
vector<vector<char>>v;

int main()
{
	scanf("%d", &t);
	
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		v.resize(m+2,vector<char>(n+2,'0'));
		
		for(int i = 1; i <= n; i++){
			char tmp[105];
			scanf("%s", &tmp);
			for(int j = 1; j <= m; j++){
				v[i][j] = tmp[j-1];
			}
			printf("%s", tmp[i]);
			puts("");
		}
	}
}
