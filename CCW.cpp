#include<stdio.h>

struct xy{
	int x, y;
};

int ccw(xy A, xy B, xy C){
	return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

int main(){
	xy ar[3];
	
	for(int i = 0; i < 3; i++){
		scanf("%d %d", &ar[i].x, &ar[i].y);
	}
	
	int val = ccw(ar[0], ar[1], ar[2]);
	
	if(val > 0) puts("1");
	if(val < 0) puts("-1");
	if(val == 0) puts("0");
	
	return 0;
}
