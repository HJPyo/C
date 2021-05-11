#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;

int n, hull[MAX];

struct xy{
	int x, y;
}ar[MAX];

int ccw(xy A, xy B, xy C){
	int tmp = (B.x-A.x) * (C.y-A.y) - (C.x-A.x) * (B.y-A.y);
	if(tmp < 0) return -1;
	if(tmp > 0) return 1;
	else return 0;
}

bool cmp(xy A, xy B){
	if(A.x == B.x) return A.y < B.y;
	else return A.x < B.x;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d %d", &ar[i].x, &ar[i].y);
	}
	
	sort(ar,ar+n,cmp);
	
	for(int i = 0; i < n; i++){
		printf("%d %d\n", ar[i].x, ar[i].y);
	}
}
