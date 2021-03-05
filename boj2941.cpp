#include<iostream>
#include<string>
using namespace std;

int len, cnt = 0;
string n;

int main()
{
	cin >> n;
	len = n.length();
	n = n + "sex";
	for(int i = 0; i < len; i++){
		char now = n[i];
		char next = n[i+1];
		switch(now){
			case 'c':{
				if(next == '=' || next == '-') i++;
				break;
			}
			case 'd':{
				if(next == 'z' && n[i+2] == '=') i+=2;
				else if(next == '-') i++;
				break;
			}
			case 'l':
			case 'n':{
				if(next == 'j') i++;
				break;
			}
			case 's':
			case 'z':{
				if(next == '=') i++;
				break;
			}
		}
		cnt++;
	}
	printf("%d", cnt);
}
