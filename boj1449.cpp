#include<stdio.h>

int main(){
	int n, k, ar[1005] = {};
	scanf("%d %d", &n, &k);
	
	for(int i = 0, j; i < n; i++){
		scanf("%d", &j);
		ar[j]++;
	}
	
	int cnt = 0;
	
	for(int i = 1; i <= 1000; i++){
		if(ar[i] == 1){
			cnt++;
			i += k-1;
		}
	}
	
	printf("%d", cnt);
}
