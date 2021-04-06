#include<stdio.h>

int main(){
	int n, cnt = 0, L = 0;
	char str[55];
	
	scanf("%d %s", &n, &str);
	
	for(int i = 0; i < n; i++){
		if(str[i] == 'L'){
			L = 1;
			i++;
		}
		cnt++;
	}
	
	printf("%d", cnt + (L ? 1 : 0));
}
