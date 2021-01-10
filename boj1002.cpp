#include<stdio.h>

int k;

int main()
{
	scanf("%d", &k);
	while(k--){
		int x1,y1,x2,y2,r1,r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		
		int D = (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);
		int Plus = (r1+r2) * (r1+r2);
		int Minus = (r1-r2) * (r1-r2);

		if(Minus < D && D < Plus)
		puts("2");
		
		else if(D == Plus || (D == Minus && D != 0))
		puts("1");
		
		else if(D < Minus || Plus < D)
		puts("0");
		
		else
		puts("-1");
	}
}
