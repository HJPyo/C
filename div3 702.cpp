#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int t;

int main()
{
	scanf("%d", &t);
	while(t--){
		int n, ar[55] = {}, cnt = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &ar[i]);
		}
		for(int i = 1; i < n; i++){
			int a = ar[i-1];
			int b = ar[i];
			if(a < b) swap(a,b);
			
			while((b << 1) < a){
				b <<= 1;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}
