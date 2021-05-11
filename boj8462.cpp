#include<cstdio>
#include<cmath>
#include<algorithm>
#define LL long long int
using namespace std;

struct st{
	int idx, x, y;
}q[100005];

int n, k, sq;
int ar[100005], ark[1000005];
LL ans[100005];

bool cmp(st a, st b){
	if(a.x / sq == b.x / sq) return a.y < b.y;
	else return a.x / sq < b.x / sq;
}

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
	}
	
	for(int i = 0; i < k; i++){
		q[i].idx = i;
		scanf("%d %d", &q[i].x, &q[i].y);
	}
	
	sq = sqrt(n);
	
	sort(q, q+k, cmp);
	
	int L = q[0].x, R = q[0].y;
	LL sum = 0;
	
	for(int i = L; i <= R; i++){
		int now = ar[i];
		ark[now]++;
		sum += (LL) now * (ark[now] * 2 - 1);
	}
	
	ans[q[0].idx] = sum;
	
	for(int i = 1; i < k; i++){
		int nL = q[i].x;
		int nR = q[i].y;
		
		while(L < nL){
			sum -= (LL) ar[L] * (ark[ar[L]] * 2 - 1);
			ark[ar[L]]--;
			L++;
		}
		while(L > nL){
			L--;
			ark[ar[L]]++;
			sum += (LL) ar[L] * (ark[ar[L]] * 2 - 1);
		}
		while(R < nR){
			R++;
			ark[ar[R]]++;
			sum += (LL) ar[R] * (ark[ar[R]] * 2 - 1);
		}
		while(R > nR){
			sum -= (LL) ar[R] * (ark[ar[R]] * 2 - 1);
			ark[ar[R]]--;
			R--;
		}
		
		ans[q[i].idx] = sum;
	}
	
	for(int i = 0; i < k; i++){
		printf("%lld\n", ans[i]);
	}
}
