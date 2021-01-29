#include<stdio.h>

int n, m;
int ar[10001] = {1,1};

int main()
{
	for(int i = 2; i < 10001; i++){
		if(ar[i] == 0){
			for(int j = i*2; j < 10001; j += i)
			ar[j] = 1;
		}
	}
	
	int sum = 0, min = 0;
	scanf("%d %d", &n, &m);
	for(int i = m; i >= n; i--){
		if(ar[i] == 0){
			sum +=i;
			min = i;
		}
	}
	
	if(sum == 0){
		puts("-1");
	}
	else{
		printf("%d\n%d", sum, min);
	}
}
