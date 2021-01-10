#include<stdio.h>

bool IsPrime(int x)
{
	if(x < 2) return false;
	for(int i = 2; i*i <= x; i++){
		if(x%i) continue;
		return false;
	}
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	if(IsPrime(n)){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}
