#include<iostream>
using namespace std;

int n, v1[1<<18], v2[1<<18], v3[1<<18], ar[1<<18];

void f(int x){
	if(x > n){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				printf("%d ", ar[i] == j);
			}
			puts("");
		}
		exit(0);
	}
	
	for(int i = 1; i <= n; i++){
		if(!v1[i] && !v2[n-i+x] && !v3[n-x+i]){		
			v1[i] = 1;
			v2[n-i+x] = 1;
			v3[n-x+i] = 1;
			
			ar[x] = i;
			f(x+1);
			
			v1[i] = 0;
			v2[n-i+x] = 0;
			v3[n-x+i] = 0;
		}
	}
}

int main(){
	scanf("%d", &n);
	v1[2] = v2[n+1] = v3[n-1] = 1;
	ar[1] = 2;
	f(2);
}
