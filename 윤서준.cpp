#include <stdio.h>
int main()
{
	int a,b,c;
	int d[10000] = {0};
	scanf("%d", &a);
	for(b = 1; b <= a; b++)
	{
		scanf("%d",&c);
		d[c]=d[c]+1;
	}
	for(b=1;b<=23;b++)
	{
		printf("%d ",d[b]);
	}
	return 0;
	
}
