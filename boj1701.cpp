#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int ar[5005], MAX = 0;
string str;

int main()
{
	cin >> str;
	for(int S = 0; S < str.length(); S++){
		int E = 0;
		for(int i = S+1; i < str.length(); i++){
			while(E != 0 && str[S+E] != str[i]) E = ar[E-1];
			if(str[i] == str[S+E]){
				MAX = max(MAX,++E);
			}
			ar[i-S] = E;
		}
	}
	cout << MAX;
}
