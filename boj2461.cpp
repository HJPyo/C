#include<stdio.h>
#include<algorithm>
#include<vector>
#define INF 1999999999
#define MAX 1005
using namespace std;

int n, k, ans = INF;
int chk[MAX], cnt;
vector<pair<int,int>>v(0,{0,0});

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			int a;
			scanf("%d", &a);
			v.push_back({a, i});
		}
	}
	
	sort(v.begin(), v.end());
	
	int L = 0, R = 0;
	
	while(R < v.size()){
		if(cnt < n){
			chk[v[R].second]++;
			if(chk[v[R].second] == 1) cnt++;
			R++;
		}
		else{
			ans = min(ans, v[R-1].first - v[L].first);
			chk[v[L].second]--;
			if(chk[v[L].second] == 0) cnt--;
			L++;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
