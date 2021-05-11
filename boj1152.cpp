#include<stdio.h>

int main(){
	char str[1000005];
	
	scanf("%s", &str);
	
	int idx = 0, cnt = 0;
	
	while(str[idx] != NULL){
		while(str[idx] == ' '){
			idx++;
		}
		while(str[idx] != ' '){
			idx++;
		}
		cnt++;
	}
	
	printf("%d", cnt);
}
