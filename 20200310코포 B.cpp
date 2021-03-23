#include<iostream>
#include<cmath>
#include<set>
using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	
	while(T--){
		int n, k;
		set<int>S;
		
		cin >> n >> k;
		
		for(int i = 0, j; i < n; i++){
			cin >> j;
			S.insert(j);
		}
		
		while(k--){
			int num = 0;
			set<int>::iterator it;
			
			for(it = S.begin(); it != S.end(); it++, num++){
				if(*it != num) break;
			}
			
			int SEX = round(double (*S.rbegin()+num) / 2);
			
			if(S.find(SEX) != S.end())
				break;
			else
				S.insert(SEX);
		}
		
		cout << S.size() << '\n';
	}
}
