#include<stdio.h>
#include<string.h>

int n, m, ar[505][505], ans = -1;

int max(int x, int y)
{
	return x > y ? x : y;
}

int I_mino_1(int x, int y)
{
	return ar[x][y] + ar[x+1][y] + ar[x+2][y] + ar[x+3][y];
}

int I_mino_2(int x, int y)
{
	return ar[x][y] + ar[x][y+1] + ar[x][y+2] + ar[x][y+3];
}

int O_mino_1(int x, int y)
{
	return ar[x][y] + ar[x+1][y] + ar[x][y+1] + ar[x+1][y+1];
}

int L_mino_1(int x, int y)
{
	return ar[x][y] + ar[x+1][y] + ar[x+2][y] + ar[x+2][y+1];
}

int L_mino_2(int x, int y)
{
	return ar[x][y] + ar[x][y+1] + ar[x+1][y+1] + ar[x+2][y+1];
}

int L_mino_3(int x, int y)
{
	return ar[x+2][y] + ar[x][y+1] + ar[x+1][y+1] + ar[x+2][y+1];
}

int L_mino_4(int x, int y)
{
	return ar[x][y] + ar[x+1][y] + ar[x+2][y] + ar[x][y+1];
}

int L_mino_5(int x, int y)
{
	return ar[x][y] + ar[x+1][y] + ar[x+1][y+1] + ar[x+1][y+2];
}

int L_mino_6(int x, int y)
{
	return ar[x][y] + ar[x][y+1] + ar[x][y+2] + ar[x+1][y+2];
}

int L_mino_7(int x, int y)
{
	return ar[x][y] + ar[x+1][y] + ar[x][y+1] + ar[x][y+2];
}

int L_mino_8(int x, int y)
{
	return ar[x+1][y] + ar[x+1][y+1] + ar[x][y+2] + ar[x+1][y+2];
}

int T_mino_1(int x, int y)
{
	return ar[x][y] + ar[x+1][y] + ar[x+2][y] + ar[x+1][y+1];
}

int T_mino_2(int x, int y)
{
	return ar[x+1][y] + ar[x][y+1] + ar[x+1][y+1] + ar[x+2][y+1];
}

int T_mino_3(int x, int y)
{
	return ar[x][y] + ar[x][y+1] + ar[x+1][y+1] + ar[x][y+2];
}

int T_mino_4(int x, int y)
{
	return ar[x+1][y] + ar[x][y+1] + ar[x+1][y+1] + ar[x+1][y+2];
}

int S_mino_1(int x, int y)
{
	return ar[x][y] + ar[x+1][y] + ar[x+1][y+1] + ar[x+2][y+1];
}

int S_mino_2(int x, int y)
{
	return ar[x+1][y] + ar[x+2][y] + ar[x][y+1] + ar[x+1][y+1];
}

int S_mino_3(int x, int y)
{
	return ar[x][y] + ar[x][y+1] + ar[x+1][y+1] + ar[x+1][y+2];
}

int S_mino_4(int x, int y)
{
	return ar[x+1][y] + ar[x][y+1] + ar[x+1][y+1] + ar[x][y+2];
}

int main()
{
	memset(ar, -1, sizeof(ar));
	
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	for(int i = 1; i <= n-3; i++){
		for(int j = 1; j <= m; j++){
			ans = max(ans,I_mino_1(i,j));
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m-3; j++){
			ans = max(ans,I_mino_2(i,j));
		}
	}
	
	for(int i = 1; i <= n-1; i++){
		for(int j = 1; j <= m-1; j++){
			ans = max(ans,O_mino_1(i,j));
		}
	}
	
	for(int i = 1; i <= n-2; i++){
		for(int j = 1; j <= m-1; j++){
			ans = max(ans,L_mino_1(i,j));
			ans = max(ans,L_mino_2(i,j));
			ans = max(ans,L_mino_3(i,j));
			ans = max(ans,L_mino_4(i,j));
			ans = max(ans,T_mino_1(i,j));
			ans = max(ans,T_mino_2(i,j));
			ans = max(ans,S_mino_1(i,j));
			ans = max(ans,S_mino_2(i,j));
		}
	}
	
	for(int i = 1; i <= n-1; i++){
		for(int j = 1; j <= m-2; j++){
			ans = max(ans,L_mino_5(i,j));
			ans = max(ans,L_mino_6(i,j));
			ans = max(ans,L_mino_7(i,j));
			ans = max(ans,L_mino_8(i,j));
			ans = max(ans,T_mino_3(i,j));
			ans = max(ans,T_mino_4(i,j));
			ans = max(ans,S_mino_3(i,j));
			ans = max(ans,S_mino_4(i,j));
		}
	}
	
	printf("%d", ans);
}
