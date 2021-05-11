#include<iostream>
#include<algorithm>
#include<vector>
#define INF 999999999
#define MAX 1001
using namespace std;

int n;
vector<vector<int>>dp(MAX,vector<int>(MAX,INF));

int f(int now, int clip){
	if(now == n) return 0;
	if(dp[now][clip] != INF) return dp[now][clip];
	dp[now][clip] = 0;
	int ret = INF;
	
	cout << now << ' ' << clip << '\n';
	
	if(now != clip){
		ret = min(ret, 1+f(now, now));
	}
	if(clip > 0){
		ret = min(ret, 1+f(now+clip, clip));
	}
	if(now > 1){
		ret = min(ret, 1+f(now-1, clip));
	}
	
	dp[now][clip] = ret;
	return ret;
}

int main(){
	cin >> n;
	cout << f(1,0);
	return 0;
}
