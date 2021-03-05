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
	
	int sum = 0, IsZero = 0;
	for(int i = 0; i < n-1; i++){
		sum += ar[i];
		if(ar[i] == 0) IsZero = 1;
	}
	if(sum % 3 != 0 || IsZero == 0){
		printf("-1\n");
		return 0;
	}
	
	sort(ar,ar+n-1,cmp);
	
	for(int i = 0; i < n-1; printf("%d", ar[i++]));
}
