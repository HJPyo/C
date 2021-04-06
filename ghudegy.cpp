#include<stdio.h>

int main(){
	char str[101];
	scanf("%s", &str);
	for(int i = 0; str[i] != NULL; i++){
		printf("%c", str[i] - 2);
	}
}
