#include<stdio.h>
#include<algorithm>
using namespace std;

int n, ar[2002];

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	sort(ar,ar+n);
	
	int cnt = 0;
	
	for(int i = 0; i < n; i++){
		int num = ar[i];
		int L = 0, R = n-1;
		
		while(L < R){
			int now = ar[L] + ar[R];
			
			if(L == i || now < num) L++;
			else if(R == i || now > num) R--;
			else{ cnt++; break; }
		}
	}
	
	printf("%d", cnt);
}
