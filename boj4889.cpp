#include<stdio.h>
#include<stack>
using namespace std;

int main(){
	int asdf = 1;
	while(1){
		char str[2002];
		stack<char>st;
		scanf("%s", &str);
		
		if(str[0] == '-') break;
		
		int cnt = 0;
		
		for(int i = 0; str[i] != NULL; i++){
			char now = str[i];
			if(now == '{'){
				st.push(now);
			}
			else{
				if(st.empty()){
					st.push('{');
					cnt++;
				}
				else{
					if(st.top() == '{') st.pop();
					else{
						st.push('{');
						cnt++;
					}
				}
			}
		}
		
		cnt += st.size() / 2;
		
		printf("%d. %d\n", asdf++, cnt);
	}
	
	return 0;
}
