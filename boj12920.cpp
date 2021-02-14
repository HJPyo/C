#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, dp[10101];
vector< pair<int,int> >item(1,{0,0});

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		int a, b, c, pack = 1;
		scanf("%d %d %d", &a, &b, &c);
		while(c > 0){
			pack = min(pack,c);
			item.push_back({a*pack,b*pack});
			c -= pack;
			pack *= 2;
		}
	}
	n = item.size()-1;
	
	for(int i = 1; i <= n; i++){
		int weight = item[i].first;
		int value = item[i].second;
		for(int j = m; j >= 1; j--){
			if(weight <= j){
				dp[j] = max(dp[j], dp[j-weight] + value);
			}
		}
	}
	
	printf("%d", dp[m]);
}

