#include<stdio.h>

int ans = 0;
char str1[4004], str2[4004], dp[4004][4004];

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	scanf("%s %s", &str1, &str2);
	
	for(int i = 0; str1[i] != NULL; i++){
		for(int j = 0; str2[j] != NULL; j++){
			if(str1[i] == str2[j]){
				if(i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = dp[i-1][j-1] + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	
	printf("%d", ans);
}
