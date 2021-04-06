#include<stdio.h>
#include<math.h>
#define INF 1999999999
#define min(x,y) (x < y ? x : y)

int n, k;
struct xy{
	int x, y;
}query[1005], dp[1005][1005][3];

int dist(int x1, int x2, int y1, int y2){
	return abs(x2-x1) + abs(y2-y1);
}

xy f(int x1, int y1, int cnt1, int x2, int y2, int cnt2, int time, int before){
	xy &now = dp[cnt1][cnt2][before];
	if(now.x) return now;
	if(time == k) return {0,0};
	
	int nx = query[time].x;
	int ny = query[time].y;
	xy Xgo = f(nx,ny,cnt1+1,x2,y2,cnt2,time+1,1);
	xy Ygo = f(x1,y1,cnt1,nx,ny,cnt2+1,time+1,2);
	Xgo.x += dist(x1,nx,y1,ny); Xgo.y = 1;
	Ygo.x += dist(x2,nx,y2,ny); Ygo.y = 2;
	
	if(Xgo.x < Ygo.x) now = Xgo;
	else now = Ygo;
	
	return now;
}

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < k; i++){
		scanf("%d %d", &query[i].x, &query[i].y);
	}
	
	printf("%d\n", f(1,1,0,n,n,0,0,0).x);
	
	return 0;
}
