#include<stdio.h>
#include<algorithm>
using namespace std;

int n, len = 0, S, E;
int L = -(1<<30), R = -(1<<30);

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &S, &E);
		if(S > R){
			len += (R-L);
			L = S;
			R = E;
		}
		else R = max(R,E);
	}
	len += R-L;
	printf("%d", len);
}
