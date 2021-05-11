#include<iostream>
#include<set>
using namespace std;

int n;
set<int>s;

int main(){
	cin >> n;
	
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			s.insert(i);
			s.insert(n / i);
		}
	}
	
	for(auto i = s.begin(); i != s.end(); i++){
		cout << *i << ' ';
	}
	
	return 0;
}
