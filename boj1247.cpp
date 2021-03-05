#include<stdio.h>
#include<algorithm>
using namespace std;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	int n = 0, ar[21] = {};
	while(~scanf("%1d", &ar[n++]));
	
	sort(ar,ar+n-1,cmp);
	
	for(int i = 0; i < n-1; printf("%d", ar[i++]));
}
