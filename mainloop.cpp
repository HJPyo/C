#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

int ar[10][10] = {};

void NowArray(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf("%d ", ar[i][j]);
		}
		puts("");
	}
}

int main(){while(true){
	/*
	if(kbhit()){
		int key = getch();
		printf("%d", key);
	}
	*/
	NowArray();
	_sleep(50);
	system("cls");
}}
