#include<stdio.h>

int n, cnt = 0, ar[105];

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	for(int i = n-2; i >= 0; i--){
		while(ar[i+1] <= ar[i]){
			ar[i]--; cnt++; 
		}
	}
	
	printf("%d", cnt);
}
