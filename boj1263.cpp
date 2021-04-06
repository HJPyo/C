#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
struct st{
	int x, y;
}ar[1005];

bool cmp(st A, st B){
	return A.y > B.y;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d %d", &ar[i].x, &ar[i].y);
	}
	
	sort(ar,ar+n,cmp);
	
	int time = ar[0].y;
	
	for(int i = 0; i < n; i++){
		while(time > ar[i].y){
			time--;
		}
		time -= ar[i].x;
	}
	
	printf("%d", time >= 0 ? time : -1);
}
