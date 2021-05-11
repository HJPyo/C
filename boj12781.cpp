#include<stdio.h>

struct xy{
	int x, y;
};

int ccw(xy A, xy B, xy C){
	int tmp =  (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
	
	if(tmp > 0) return 1;
	if(tmp < 0) return -1;
	return 0;
}

int main(){
	xy ar[4];
	
	for(int i = 0; i < 4; i++){
		scanf("%d %d", &ar[i].x, &ar[i].y);
	}
	
	int ans = ccw(ar[0], ar[1], ar[2]) * ccw(ar[0], ar[1], ar[3]);
	
	printf("%d", ans < 0);
}
