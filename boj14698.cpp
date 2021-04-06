#include<cstdio>
#include<queue>
#define LL long long int
#define MOD 1000000007
using namespace std;

int T;

int main(){
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		
		priority_queue<LL,vector<LL>,greater<LL>>pq;
		for(int i = 0; i < n; i++){
			LL a;
			scanf("%lld", &a);
			pq.push(a);
		}
		
		LL ans = 1;
		while(pq.size() > 1){
			LL s1 = pq.top(); pq.pop();
			LL s2 = pq.top(); pq.pop();
			LL s3 = s1 * s2;
			ans = (ans * (s3 % MOD)) % MOD;
			pq.push(s3);
		}
		
		printf("%lld\n", ans);
	}
}
