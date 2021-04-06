#include<stdio.h>

int n, k, num[500005];

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%1d", &num[i]);
	}
	
	int del = 0, big = -1;
	for(int i = 0; i < k; i++){
		if(big < num[i]){
			del = i;
			big = num[i];
		}
	}
	
	printf("%d %d", del, big);
}
