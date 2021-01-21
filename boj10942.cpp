#include<stdio.h>
#include<vector>
using namespace std;

int n, m, ar[2001], dp[2001][2001];
vector<pair<int,int> >v;

int f(int L, int R)
{
	v.clear();
	
	while(L<R){
		if(dp[L][R]){
			return 1;
		}
		else if(ar[L] == ar[R]){
			v.push_back(make_pair(L++,R--));
		}
		else{
			return 0;
		}
	}
	
	for(int i = 0; i < v.size(); i++){
		dp[v[i].first][v[i].second] = 1;
	}
	
	return 1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &ar[i]);
		
	scanf("%d", &m);
	while(m--){
		int L, R;
		scanf("%d %d", &L, &R);
		printf("%d\n", f(L,R));
	}
}
