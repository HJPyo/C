#include<stdio.h>
#include<vector>
using namespace std;

int t;

int main()
{
	scanf("%d", &t);
	while(t--){
		int n, ar1[202] = {}, ar2[202] = {};
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			double a, b;
			scanf("%f &f", &a, &b);
			ar1[i] = (int) a * 10.0;
			ar2[i] = (int) b * 10.0;
			printf("%d %d\n", ar1[i], ar2[i]);
		}
		
		
	}
}
