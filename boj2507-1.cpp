#include<stdio.h>

int n, v1[16], v2[16], Vis[16], dp[16][2];

int f(int x, int y)
{
	if(x == 15) y = 1;
	if(y == 1 && x == 0) return 1; //미션성공  
	if(y && !v2[x]) return 0; //약한섬은 혼자서 가 
//	if(dp[x][y]) return dp[x][y];
//	printf("%d %d\n", x, y);
	for(int i = x+v1[x]; i >= x-v1[x]; i--)
	{
		if(i < 0 || i > 15 || i == x) continue; //범위 벗어나지마 
		if(!v1[i]) continue; //섬 없으면 넘어가 
		if(i != 0 && Vis[i]) continue; //갔던곳 또 가지마 
		
		Vis[x] = 1;
		dp[x][y] += f(i,y);
		Vis[x] = 0;
	}
//	puts("");
	return dp[x][y];
}

int main()
{
	scanf("%d", &n);
	while(n--){
		int a, b, c;
		scanf("%d %d %d", &a, &b ,&c);
		v1[a] = b;
		v2[a] = c;
	}
	printf("%d", f(0,0));
}
