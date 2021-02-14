#include<stdio.h>

int k;

int main()
{
	scanf("%d", &k);
	while(k--){
		int fx, fy;
		char order[100004];
		scanf("%d %d", &fx, &fy);
		scanf("%s", &order);
		
		int nx = 0, ny = 0;
		for(int i = 0; order[i] != NULL; i++){
			if(nx < fx){
				if(order[i] == 'R') nx++;
			}
			if(nx > fx){
				if(order[i] == 'L') nx--;
			}
			if(ny < fy){
				if(order[i] == 'U') ny++;
			}
			if(ny > fy){
				if(order[i] == 'D') ny--;
			}
		}
		
		printf("%s\n", (nx == fx && ny == fy) ? "YES" : "NO");
	}
}
