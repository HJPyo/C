#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;

int main()
{
	char now, str[105];
	stack<char>s;
	queue<char>ans;
	scanf("%s", &str);
	
	for(int i = 0; str[i] != NULL; i++){
		now = str[i];
		switch(now){
			case '+':
			case '-':{
				while(!s.empty() && s.top() != '('){
					ans.push(s.top());
					s.pop();
				}
				s.push(now);
				break;
			}
			case '*':
			case '/':{
				while(!s.empty() && (s.top() == '*' || s.top() == '/')){
					ans.push(s.top());
					s.pop();
				}
				s.push(now);
				break;
			}
			case '(':{
				s.push(now);
				break;
			}
			case ')':{
				while(!s.empty() && s.top() != '('){
					ans.push(s.top());
					s.pop();
				}
				s.pop();
				break;
			}
			default :{
				ans.push(now);
				break;
			}
		}
	}
	while(!s.empty()){
		ans.push(s.top());
		s.pop();
	}
	while(!ans.empty()){
		printf("%c", ans.front());
		ans.pop();
	}
}
