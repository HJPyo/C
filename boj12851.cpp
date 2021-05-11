#include<bits/stdc++.h>
#define MAX 200002
using namespace std;

int n, k, flag, dy[MAX][101];
vector<int>d(MAX,MAX);
queue<pair<int,int>>q;

int dp[3] = {1,-1, 0};
int dm[3] = {0, 0, 1};

int f(int x, int cnt){
	if(cnt > flag) return 0;
	if(x == k) return 1;
	if(dy[x][cnt] != -1) return dy[x][cnt];
	dy[x][cnt] = 0;
	printf(">>%d %d\n", x, cnt);
	for(int i = 0; i < 3; i++){
		int next = (x + dp[i]) << dm[i];
		if(0 <= next && next < MAX){
			dy[x][cnt] += f(next, cnt+1);
		}
	}
	
	return dy[x][cnt];
}

int main(){
	cin >> n >> k;
	
	q.push({0,n});
	
	while(!q.empty()){
		int dis = q.front().first;
		int now = q.front().second;
		q.pop();
		
		if(d[now] <= dis)
			continue;
		
		d[now] = dis;
		
		if(now == k){
			break;
		}
		
		for(int i = 0; i < 3; i++){
			int next = (now + dp[i]) << dm[i];
			if(0 <= next && next < MAX){
				q.push({dis+1,next});
			}
		}
	}
	
	flag = d[k];
	
	cout << flag << '\n' << f(n,0);
}
