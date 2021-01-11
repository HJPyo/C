#include<stdio.h>

int n, sum;

int main()
{
	scanf("%d", &n);
	sum = n;
	while(n--){
		int vis[128] = {};
		char str[101];
		scanf("%s", &str);
		
		for(int i = 0; str[i] != NULL; i++){
			if(vis[str[i]] == 0){
				vis[str[i]] = 1;
				continue;
			}
			else if(str[i] == str[i-1]){
				continue;
			}
			sum--;
			break;
		}
	}
	
	printf("%d", sum);
}
