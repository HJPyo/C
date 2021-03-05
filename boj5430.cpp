#include<iostream>
#include<deque>
#include<string>
using namespace std;

int k;

int main()
{
	cin >> k;
	
	while(k--){
		int n, str_len, order_len, size;
		string order, str;
		deque<int>ar;
		
		cin >> order >> n >> str;
		str_len = str.length();
		order_len = order.length();
		
		for(int i = 0; i < str_len; i++){
			if('0' <= str[i] && str[i] <= '9'){
				int tmp = 0;
				while('0' <= str[i] && str[i] <= '9'){
					tmp *= 10;
					tmp += str[i] - '0';
					i++;
				}
				ar.push_back(tmp);
			}
		}
		
		int ptr = 0;
		for(int i = 0; i < order_len; i++){
			if(order[i] == 'R'){
				ptr = (ptr+1) % 2;
			}
			else{
				if(ar.empty()){
					cout << "error\n";
					goto END;
				}
				else if(ptr == 0){
					ar.pop_front();
				}
				else{
					ar.pop_back();
				}
			}
		}
		size = ar.size();
		
		cout << '[';
		for(int i = 0; i < size; i++){
			cout << ar[(ptr == 0 ? i : size-i-1)];
			if(i != size-1) cout << ',';
		}
		cout << "]\n";
		
		END:
		ar.clear();
	}
}
