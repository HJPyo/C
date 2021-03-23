#include<iostream>

int n, m, k;
char tmp[33];

void f(int x, int y)
{
	if(y > m) return;
	if(x == n){
		if(y < m) return;
		if(k == 0){
			printf("%s", tmp);
			exit(0);
		}
		k--;
		return;
	}
	
	printf("%s\n", tmp);
	
	tmp[x] = '0';
	f(x+1,y);
	tmp[x] = '1';
	f(x+1,y+1);
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	f(0,0);
}
