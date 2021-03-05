#include<stdio.h>
#include<stack>
using namespace std;

int ans = 0, tmp = 1;
char str[33];
stack<char>st;

int main()
{
	scanf("%s", &str);
	
	for(int i = 0; str[i] != NULL; i++){
		char now = str[i];
		if(now == '('){
			tmp <<= 1;
			st.push(now);
		}
		else if(now == '['){
			tmp *= 3;
			st.push(now);
		}
		else if(now == ')'){
			if(st.empty() || st.top() != '('){
				printf("0"); return 0;
			}
			if(str[i-1] == '(') ans += tmp;
			tmp >>= 1;
			st.pop();
		}
		else if(now == ']'){
			if(st.empty() || st.top() != '['){
				printf("0"); return 0;
			}
			if(str[i-1] == '[') ans += tmp;
			tmp /= 3;
			st.pop();
		}
	}
	
	printf("%d", st.empty() ? ans : 0);
}
