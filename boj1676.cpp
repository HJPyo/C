#include<stdio.h>
#define min(x,y) (x < y ? x : y)

int n, _2 = 0, _5 = 0;

int main(){
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		int now = i;
		
		while(now % 2 == 0){
			_2++;
			now /= 2;
		}
		
		while(now % 5 == 0){
			_5++;
			now /= 5;
		}
	}
	
	printf("%d", min(_2,_5));
}
