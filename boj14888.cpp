#include<stdio.h>
#include<algorithm>
#define INF 2111111111
using namespace std;

int n, ar[11], op[4], MAX = -INF, MIN = INF;

void f(int x, int y)
{
	if(x == n){
		MAX = max(MAX,y);
		MIN = min(MIN,y);
		return;
	}
	int now = ar[x];
	if(op[0]){ op[0]--; f(x+1,y+now); op[0]++; }
	if(op[1]){ op[1]--; f(x+1,y-now); op[1]++; }
	if(op[2]){ op[2]--; f(x+1,y*now); op[2]++; }
	if(op[3]){ op[3]--; f(x+1,y/now); op[3]++; }
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; scanf("%d", &ar[i++]));
	for(int i = 0; i < 4; scanf("%d", &op[i++]));
	f(1,ar[0]);
	printf("%d\n%d", MAX, MIN);
}
