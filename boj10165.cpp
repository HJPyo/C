#include<stdio.h>
#include<algorithm>
#define MAX 500005
using namespace std;

int n, k;
struct st{
	int s, e, idx;
}ar[MAX];

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		
		if(b < a) b += n;
		ar[i] = {a,b,i};
	}
	
	sort(ar+1,ar+k+1,[](st x, st y){
		if(x.e == y.e) return x.s < y.s;
		else return x.e < y.e;
	});
	
	for(int i = 1; i <= k; i++){
		printf("%d %d %d\n", ar[i].s, ar[i].e, ar[i].idx);
	}
}
