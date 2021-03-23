#include<stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	double ki;
	
	if(n < 150){
		ki = (double) n - 100;
	}
	else if(n < 160){
		ki = (double) (n - 150) / 2 + 50;
	}
	else{
		ki = (double) (n - 100) * 0.9;
	}
	
	double bi = (m - ki) * 100 / ki;
	
	printf("%lf %lf\n", ki, bi); 
	
	if(bi <= 10.0){
		printf("정상");
	}
	else if(bi <= 20.0){
		printf("과체중");
	}
	else{
		printf("비만"); 
	} 
}
