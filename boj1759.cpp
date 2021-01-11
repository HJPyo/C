#include<stdio.h>
#include<algorithm>
using namespace std;

int n, m, ar[18];


int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &ar[i]);
	}
	sort(ar,ar+m);
	for(int i = 0; i < m; i++)
	printf("%c", ar[i]);
}
