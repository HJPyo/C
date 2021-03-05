#include<stdio.h>
#include<math.h>

int n, ar[8], vis[8], ans = 0;

int max(int x, int y)
{
	return x > y ? x : y;
}

void f(int x, int y, int z)
{
	if(x == n){
		ans = max(ans,y);
		return;
	}
	for(int i = 0; i < n; i++){
		if(vis[i] == 0){
			vis[i] = 1;
			f(x+1, y+abs(ar[z]-ar[i]), i);
			vis[i] = 0;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; scanf("%d", &ar[i++]));
	for(int i = 0; i < n; i++){
		vis[i] = 1;
		f(1,0,ar[i]);
		vis[i] = 0;
	}
	printf("%d", ans);
}
