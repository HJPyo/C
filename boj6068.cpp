#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
struct st{
	int s, e;
}ar[1001];

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d %d", &ar[i].s, &ar[i].e);
	}
	
	sort(ar,ar+n,[](st x, st y){
		return x.e > y.e;
	});
	
	int now = ar[0].e;
	
	for(int i = 0; i < n; i++){
		now = min(now,ar[i].e);
		now -= ar[i].s;
	}
	
	printf("%d", max(now,-1));
}
