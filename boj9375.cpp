#include<iostream>
#include<string>
#include<map>
using namespace std;

int TC;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> TC;
	
	while(TC--){
		int n;
		map<string,int> cloth;
		
		cin >> n;
		
		for(int i = 0; i < n; i++){
			string _, type;
			cin >> _ >> type;
			
			if(cloth.find(type) != cloth.end()){
				cloth[type] = cloth[type] + 1;;
			}
			else{
				cloth[type] = 1;
			}
			
			cout << type << " : " << cloth[type] << '\n';
		}
		
		cout << '\n';
	}
	
	return 0;
}
