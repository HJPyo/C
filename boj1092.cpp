#include<stdio.h>
#include<algorithm>
using namespace std;

int n, m, c[51], b[10001], time = 0, finished = 0;

bool cmp(int x, int y){ return x > y; }

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}
	
	sort(c,c+n,cmp);
	sort(b,b+m,cmp);
	
	while(finished != m){
		int flag = 0;
		time++;
		for(int crane = 0, box = 0; box < m; box++){
			if(c[crane] >= b[box] && b[box] != 0){
				flag = 1;
				b[box] = 0;
				crane++;
				finished++;
			}
		}
		if(flag == 0){
			time =  -1;
			break;
		}
	}
	
	printf("%d", time);
}
