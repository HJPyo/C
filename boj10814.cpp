#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct info{
	int idx, age;
	string name;
}ar[100001];
int n;

bool cmp(info x, info y)
{
	if(x.age == y.age) return x.idx < y.idx;
	else return x.age < y.age;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> ar[i].age >> ar[i].name;
		ar[i].idx = i;
	}
	
	sort(ar,ar+n,cmp);
	
	for(int i = 0; i < n; i++){
		cout << ar[i].age << " "+ar[i].name << '\n';
	}
}
