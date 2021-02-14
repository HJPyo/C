#include<stdio.h>

int n, k, cnt = 0;
char str[20002];

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", &str);
	
	for(int i = 0; i < n; i++){
		if(str[i] == 'P'){
			for(int j = i-k; j <= i+k; j++){
				if(j < 0 || j >= n) continue;
				if(str[j] == 'H'){
					str[j] = '.';
					cnt++;
					break;
				}
			}
		}
	}
	
	printf("%d\n", cnt);
}
