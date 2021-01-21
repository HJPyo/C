#include<stdio.h>
#include<algorithm>
using namespace std;

int n, m, ar[51][51];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		char str[51];
		scanf("%s", &str);
		for(int j = 0; j < m; j++){
			ar[i][j] = str[j] == 'B' ? 1 : 0;
		}
	}
	
	int ans = 999999999;
	for(int I = 0; I <= n-8; I++){
		for(int J = 0; J <= m-8; J++){
			
			int cnt = 0;
			for(int i = 0; i < 8; i++){
				for(int j = 0; j < 8; j++){
					int _i = i+I, _j = j+J;
					if(ar[_i][_j] == (_i%2 == _j%2)) cnt++;
				}
			}
			cnt = min(cnt, 64-cnt);
			ans = min(cnt, ans);
			
		}
	}
	
	printf("%d", ans);
}
