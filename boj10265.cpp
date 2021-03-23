#include<stdio.h>
#include<vector>
#include<stack>
#define MAX 1001
using namespace std;

int n, k;
vector<int>needs[MAX], R_needs[MAX], vis(MAX,0), boss(MAX,0);
vector<vector<int>>SCC;
stack<int>st;

vector<int>item;

void dfs(int x)
{
	vis[x] = 1;
	
	for(int i = 0; i < needs[x].size(); i++){
		int next = needs[x][i];
		if(!vis[next]) dfs(next);
	}
	
	st.push(x);
	return;
}

vector<int> R_dfs(int x)
{
	vis[x] = 0;
	vector<int>tmp1;
	tmp1.push_back(x);
	
	for(int i = 0; i < R_needs[x].size(); i++){
		int next = R_needs[x][i];
		if(vis[next]){
			vector<int>tmp2 = R_dfs(next);
			tmp1.insert(tmp1.end(),tmp2.begin(),tmp2.end());
		}
	}
	
	return tmp1;
}

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 1, j; i <= n; i++){
		scanf("%d", &j);
		needs[i].push_back(j);
		R_needs[j].push_back(i);
	}
	
	for(int i = 1; i <= n; i++){
		if(!vis[i]) dfs(i);
	}
	
	while(!st.empty()){
		int now = st.top();
		st.pop();
		
		if(vis[now]){
			SCC.push_back(R_dfs(now));
			
			int now = SCC.size()-1;
			int now_size = SCC[now].size();
			if(now_size > 2){
				for(int i = 0; i < now_size; i++){
					boss[SCC[now][i]] = SCC[now][i];
				}
			}
			else{
				boss[SCC[now][0]] = needs[SCC[now][0]][0];
			}
		}
	}
	
	for(int i = 0; i < SCC.size(); i++){
		for(int j = 0; j < SCC[i].size(); j++){
			printf("[%d]", SCC[i][j]);
		}
		puts("");
	}
	
	for(int i = 1; i <= n; i++){
		printf("%d ", boss[i]);
	}
}
