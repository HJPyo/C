#include<stdio.h>

int n, ar[3333][6666];

void f(int x, int y, int v)
{
	if(v == 3){
		ar[x][y+2] = 
		ar[x+1][y+1] = 
		ar[x+1][y+3] = 
		ar[x+2][y] = 
		ar[x+2][y+1] = 
		ar[x+2][y+2] = 
		ar[x+2][y+3] =
		ar[x+2][y+4] = 1;
		return;
	}
	int nv = v/2;
	f(x,y+(nv),nv);
	f(x+nv,y,nv);
	f(x+nv,y+(nv*2),nv);
}

int main()
{
	scanf("%d", &n);
	
	f(0,0,n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (n<<1); j++){
			printf("%c", ar[i][j] ? '*' : ' ');
		}
		puts("");
	}
}
