#include<iostream>
#include<string>
#include<stack>
using namespace std;

int len;
string PPAP;
stack<char>st;

int main(){
	cin >> PPAP;
	len = PPAP.length();
	
	for(int i = 0; i < len; i++){
		char now = PPAP[i];
		if(now == 'P'){
			if(st.empty()) st.push(now);
			else if(st.top() == 'A'){
				if(st.size() < 3) goto END;
				st.pop();
				for(int j = 0; j < 2; j++){
					if(st.top() == 'A'){
						goto END;
					}
					else{
						st.pop();
					}
				}
				st.push(now);
			}
			else{
				st.push(now);
			}
		}
		else{
			st.push(now);
		}
	}
	
	if(st.top() == 'P') st.pop();
	
	END:
	
	cout << (st.empty() ? "PPAP" : "NP");
}
