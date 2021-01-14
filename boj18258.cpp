#include<iostream>
#include<string>
using namespace std;

int n, ar[2000002], Size = 0;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
    string s;
    int x, i;
	while(n--){
		cin >> s;
		if(s == "push"){
			cin >> x;
			ar[Size++] = x;
		}
		else if(s == "pop"){
			if(!Size){
				cout << "-1\n";
				continue;
			}
			cout << ar[0] << '\n';
			if(--Size > 0)
			for(i = 0; i < Size; i++)
			ar[i] = ar[i+1];
		}
		else if(s == "size"){
			cout << Size << '\n';
		}
		else if(s == "empty"){
			cout << (Size > 0 ? 0 : 1) << '\n';
		}
		else if(s == "front"){
			cout << (Size > 0 ? ar[0] : -1) << '\n';
		}
		else{
			cout << (Size > 0 ? ar[Size-1] : -1) << '\n';
		}
	}
}
