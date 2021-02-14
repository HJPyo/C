#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

/*
kbhit() : IsHit
getch() : GetKey
*/

#define MAX_X 20
#define MAX_Y 8

int GameConsol[MAX_X][MAX_Y];

int main()
{
	for(int i = 0; i < MAX_X; i++){
		for(int j = 0; j < MAX_Y; j++){
			GameConsol[i][j] = 1;
		}
	}
}
