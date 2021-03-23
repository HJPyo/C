#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	auto SEED = time(NULL);
	
	srand(SEED);
	
	cout << "SEED : " << SEED << '\n';
	
	int ar[10];
	
	for(int i = 0; i < 10; i++){
		ar[i] = rand() % 1234;
	}
	
	sort(ar,ar+10,[](int x, int y){
		return x < y;
	});
	
	for(auto i: ar){
		cout << i << '\n';
	}
}
