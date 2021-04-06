#include<stdio.h>
#define max(x,y) (x > y ? x : y)

int main(){
	int n, ar1[100005], ar2[100005];
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ar1[i]);
		ar2[n-i-1] = ar1[i];
	}
	
	int ans = 0;
	
	for(int i = 0, tmp = 0, cnt = 0; i < n; i++){
		if(ar1[i] >= tmp){
			cnt++;
		}
		else cnt = 1;
		tmp = ar1[i];
		ans = max(ans,cnt);
	}
	
	for(int i = 0, tmp = 0, cnt = 0; i < n; i++){
		if(ar2[i] >= tmp){
			cnt++;
		}
		else cnt = 1;
		tmp = ar2[i];
		ans = max(ans,cnt);
	}
	
	printf("%d", ans);
}
