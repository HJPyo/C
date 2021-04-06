#include<stdio.h>
#include<math.h>
#define LL long long int

int n, m, k, sq;
LL arr[1000005], box[1005];

int idx, l, r;
LL val;

void update(){
	int id = idx/sq;
	int st = id * sq;
	int en = st + sq;
	
	arr[idx] = val;
	box[id] = 0;
	
	for(int i = st; i < en; i++){
		box[id] += arr[i];
	}
}

LL query(){
	LL tmp = 0;
	while(l <= r && l % sq != 0) tmp += arr[l++];
	while(l <= r && (r+1) % sq != 0) tmp += arr[r--];
	for(int i = l; i <= r; i += sq) tmp += box[i/sq];
	return tmp;
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	sq = (int) sqrt(n);
	
	for(int i = 1; i <= n; i++){
		scanf("%lld", &arr[i]);
		box[i/sq] += arr[i];
	}
	
	for(int i = 0; i < m+k; i++){
		int a;
		scanf("%d", &a);
		
		if(a == 1){
			scanf("%d %lld\n", &idx, &val);
			update();
		}
		else{
			scanf("%d %d", &l, &r);
			printf("%lld\n", query());
		}
	}
}
