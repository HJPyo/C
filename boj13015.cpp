#include<stdio.h>

int n;

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) printf("*");
	for(int i = 0; i < n*2-3; i++) printf(" ");
	for(int i = 0; i < n; i++) printf("*");
	
	puts("");
	
	for(int i = 0; i < n-2; i++){
		for(int j = 0; j < i+1; j++) printf(" ");
		printf("*");
		for(int j = 0; j < n-2; j++) printf(" ");
		printf("*");
		for(int j = 0; j < (n-i)*2-5; j++) printf(" ");
		printf("*");
		for(int j = 0; j < n-2; j++) printf(" ");
		printf("*");
		
		puts("");
	}
	
	for(int j = 0; j < n-1; j++) printf(" ");
	printf("*");
	for(int j = 0; j < n-2; j++) printf(" ");
	printf("*");
	for(int j = 0; j < n-2; j++) printf(" ");
	printf("*");
	
	puts("");
	
	for(int i = n-3; i >= 0; i--){
		for(int j = 0; j < i+1; j++) printf(" ");
		printf("*");
		for(int j = 0; j < n-2; j++) printf(" ");
		printf("*");
		for(int j = 0; j < (n-i)*2-5; j++) printf(" ");
		printf("*");
		for(int j = 0; j < n-2; j++) printf(" ");
		printf("*");
		
		puts("");
	}
	
	for(int i = 0; i < n; i++) printf("*");
	for(int i = 0; i < n*2-3; i++) printf(" ");
	for(int i = 0; i < n; i++) printf("*");
}
