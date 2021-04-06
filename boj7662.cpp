#include<iostream>
#include<set>
using namespace std;

int T;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	
	while(T--){
		int n;
		multiset<int>st;
		cin >> n;
		
		while(n--){
			char query;
			int num;
			cin >> query >> num;
			
			if(query == 'I'){
				st.insert(num);
			}
			else{
				if(st.empty()) continue;
				if(num == 1){
					st.erase(--st.end());
				}
				else{
					st.erase(st.begin());
				}
			}
		}
		
		if(st.empty()) cout << "EMPTY\n";
		else cout << *(--st.end()) << ' ' << *st.begin() << '\n';
	}
}
