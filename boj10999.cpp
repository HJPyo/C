#include<stdio.h>
#include<math.h>
#define LL long long int

int n, m, k, sq;
LL arr[1000005], box[1005], add[1005];

int l, r;
LL val;

void update(){
	while(l <= r && l % sq != 0){
		arr[l] += val;
		box[l/sq] += val;
		l++;
	}
	while(l <= r && (r+1) & sq != 0){
		arr[r] += val;
		box[r/sq] += val;
		r--;
	}
	while(l <= r){
		box[l/sq] += val * sq;
		add[l/sq] += val * sq;
		l += sq;
	}
}

LL query(){
	LL tmp = 0;
	while(l <= r && l % sq != 0){
		tmp += arr[l] + (add[l/sq] / sq);
		l++;
	}
	while(l <= r && (r+1) & sq != 0){
		tmp += arr[r] + (add[r/sq] / sq);
		r--;
	}
	while(l <= r){
		tmp += box[l/sq];
		l += sq;
	}
	return tmp;
}

void debug(){
	for(int i = 1; i <= n; i++){
		printf("%lld ", arr[i]);
	}
	puts("");
	for(int i = 1; i <= n/sq; i++){
		printf("%lld ", box[i]);
	}
	puts("");
	for(int i = 1; i <= n/sq; i++){
		printf("%lld ", add[i]);
	}
	puts("");
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	sq = sqrt(n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &arr[i]);
		box[i/sq] = arr[i];
	}
	for(int i = 0; i < m+k; i++){
		int a;
		scanf("%d", &a);
		if(a == 1){
			scanf("%d %d %lld", &l, &r, &val);
			update();
		}
		else{
			scanf("%d %d", &l, &r);
			printf("%lld\n", query());
		}
		debug();
	}
}
