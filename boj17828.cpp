#include<stdio.h>

int n, k, ar[26];

int main(){
	scanf("%d %d", &n, &k);
	
	if(n * 26 < k || n > k){
		printf("!");
	}
	else{
		int sum = n;
		ar[0] = n;
		
		for(int i = 25; sum != k; i--){
			while(sum + i <= k){
				ar[0]--;
				ar[i]++;
				sum += i;
			}
		}
		
		for(int i = 0; i < 26; i++){
			for(int j = 0; j < ar[i]; j++){
				printf("%c", 'A' + i);
			}
		}
	}
	
	return 0;
}
