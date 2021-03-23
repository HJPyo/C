#include<stdio.h>
#include<string.h>
#define max(x,y) (x > y ? x : y)

int n, table[26];
char str[100001];

int main()
{
	scanf("%d", &n);
	scanf("%s", &str);
	
	int ans = -1, len = strlen(str), vary = 1;
	int L = 0, R = 0;
	
	table[str[0]-'a']++;
	
	while(L < len-1 || R < len-1){
		if(vary <= n) ans = max(ans,R-L+1);
		
		if(vary <= n && R < len-1){
			if(++table[str[R+1]-'a'] == 1) vary++;
			R++;
		}
		else{
			if(--table[str[L]-'a'] == 0) vary--;
			L++;
		}
	}
	
	printf("%d", ans);
}
