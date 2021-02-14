#include<stdio.h>
#include<vector>
using namespace std;

int n, m, k, kid[30003], kid_vis[30003], dp[30003];
vector<int>kid_len[30003];
vector< pair<int,int> >candy(1,make_pair(0,0));

pair<int,int> group(int x)
{
	pair<int,int> tmp = make_pair(1,kid[x]);
	kid_vis[x] = 1;
	for(int i = 0; i < kid_len[x].size(); i++){
		int next = kid_len[x][i];
		if(!kid_vis[next]){
			pair<int,int> now = group(next);
			tmp.first += now.first;
			tmp.second += now.second;
		}
	}
	return tmp;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &kid[i]);
	}
	
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		kid_len[a].push_back(b);
		kid_len[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++){
		if(!kid_vis[i]){
			candy.push_back(group(i));
		}
	}
	
	int candy_num = candy.size()-1;
	
	for(int i = 1; i <= candy_num; i++){
		int Crying = candy[i].first;
		int CanGet = candy[i].second;
		for(int j = k; j >= 1; j--){
			if(Crying < j){
				dp[j] = max(dp[j], dp[j-Crying] + CanGet);
			}
		}
	}
	
	printf("%d", dp[k]);
}
