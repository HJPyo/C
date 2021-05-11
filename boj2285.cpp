#include<stdio.h>

int n, ar[55], cnt = 0;

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	while(true){
		int chk = 0;
		
		for(int i = 0; i < n; i++){
			if(ar[i] % 2 == 1){
				ar[i]--;
				cnt++;
			}
			if(ar[i] != 0){
				chk = 1;
			}
		}
		
		if(chk == 0) break;
		
		for(int i = 0; i < n; i++){
			ar[i] >>= 1;
		}
		
		cnt++;
	}
	
	printf("%d", cnt);
	
	return 0;
}
