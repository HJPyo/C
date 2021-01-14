#include<stdio.h>
#include<cstring>
#include<list>
using namespace std;

char str[100001];
int k, cur;

int main()
{
	scanf("%s %d", &str, &k);
	cur = strlen(str);
	while(k--){
		char query, x;
		scanf("%c", &query);
		
		if(query == 'L'){
			if(cur > 0) cur--;
		}
		else if(query == 'D'){
			if(cur < strlen(str)) cur++;
		}
		else if(query == 'B'){
			if(cur > 0){
				for(int i = cur--, j = strlen(str); i < j; i++){
					str[i-1] = str[i];
					str[i] = NULL;
				}
			}
		}
		else{
			scanf("%c", &x);
			for(int i = cur, j = strlen(str); i < j; j--){
				str[i] = str[i-1];
			}
			str[cur++] = x;
		}
	}
	printf("%s", str);
}
