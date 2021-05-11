#include<stdio.h>
#include<algorithm>
#include<cmath>
#define MAX 100005
using namespace std;

int n, k, sq;
int ar[MAX];

struct query{
	int l, r, idx;
}q[MAX];

int main(){
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
	}
	
	scanf("%d", &k);
	
	for(int i = 1; i <= k; i++){
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].idx;
	}
	
	sq = sqrt(n);
	
	sort(q+1,q+k+1,[](query x, query y){
		if(x.l / sq == y.l / sq) return x.r < y.r;
		else return (x.l / sq) < (y.l / sq);
	});
	
	int 
	
	
}
