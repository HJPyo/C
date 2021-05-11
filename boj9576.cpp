#include<stdio.h>
#include<algorithm>
using namespace std;

struct st{
	int l, r;
};

bool cmp(st x, st y){
	if(x.r == y.r) return x.l < y.l;
	else return x.r < y.r;
}

int main(){
	int TC;
	
	scanf("%d", &TC);
	
	while(TC--){
		int n, k, cnt = 0, chk[1001] = {};
		st ar[1001] = {};
		
		scanf("%d %d", &n, &k);
		
		for(int i = 0; i < k; i++){
			scanf("%d %d", &ar[i].l, &ar[i].r);
		}
		
		sort(ar, ar+k, cmp);
		
		for(int i = 0; i < k; i++){
			int l = ar[i].l;
			int r = ar[i].r;
			
			for(int idx = l; idx <= r; idx++){
				if(!chk[idx]){
					chk[idx] = 1;
					cnt++;
					break;
				}
			}
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}
