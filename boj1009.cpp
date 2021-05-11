#include<stdio.h>

int n;

int main(){
	scanf("%d", &n);
	
	while(n--){
		int a, b, c = 1;
		scanf("%d %d", &a, &b);
		
		for(int i = 0; i < b; i++){
			c = (c * a) % 10;
		}
		
		printf("%d\n", c == 0 ? 10 : c);
	}
	
	return 0;
}
