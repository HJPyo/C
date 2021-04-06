#include<stdio.h>
#include<math.h>

int main(){
	for(int i = 0; i < 11; i++){
		printf("%d ", 3);
	}
	puts("");
	for(int i = 0; i < pow(3,11); i++){
		printf("%d ", 0);
		if(i % 20 == 0) puts("");
	}
}
