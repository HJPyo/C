#include<stdio.h>
#define INF 999999999

int goal, n, button[10], now, cnt, ans;

int Min(int a, int b)
{
	return a < b ? a : b;
}

int IsNum(int x)
{
	int i, j;
	for(i = x, j = 0; i; i/=10, j++){
		if(button[i%10]) return INF;
	}
	if(x == 0) return button[0] ? INF : 1;
	return j;
}

int main()
{
	scanf("%d %d", &goal, &n);
	
	for(int i = 0, j; i < n; i++){
		scanf("%d", &j);
		button[j] = 1;
	}
	
	if(goal > 100){
		now = 100; cnt = 0;
		while(now != goal){
			now++; cnt++;
			cnt = Min(cnt, IsNum(now));
		}
		ans = cnt;
		
		now = goal; cnt = 0;
		while(IsNum(now) == INF){
			now++; cnt++;
			if(now > 999999){
				cnt = INF;
				break;
			}
		}
		cnt+=IsNum(now);
		ans = Min(ans, cnt);
		
		printf("%d", ans);
	}
	else if(goal < 100){
		now = 100; cnt = 0;
		while(now != goal){
			now--; cnt++;
			cnt = Min(cnt, IsNum(now));
		}
		ans = cnt;
		
		now = goal; cnt = 0;
		while(IsNum(now) == INF){
			now--; cnt++;
			if(now < 0){
				cnt = INF;
				break;
			}
		}
		cnt+=IsNum(now);
		ans = Min(ans, cnt);
		
		printf("%d", ans);
	}
	else{
		printf("0");
	}
}
