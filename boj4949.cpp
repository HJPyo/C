#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	while(true){
		string str, flag = "no";
		getline(cin, str);
		if(str == ".") break;
		
		int len = str.length();
		stack<char>S;
		for(int i = 0; i < len; i++){
			char now = str[i];
			switch(now){
				case '(': { S.push('('); break; }
				case '[': { S.push('['); break; }
				case ')': {
					if(!S.empty()){
						if(S.top() == '(') S.pop();
						else goto END;
					}
					else goto END;
					break;
				}
				case ']': {
					if(!S.empty()){
						if(S.top() == '[') S.pop();
						else goto END;
					}
					else goto END;
					break;
				}
				default : { break; }
			}
		}
		if(S.empty()) flag = "yes";
		END:
		cout << flag << '\n';
	}
}
