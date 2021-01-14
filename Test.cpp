#include<iostream>
#include<cstring>
#include<list>
using namespace std;

int main()
{
	char C[10] = "Hello";
	list<char>L(&C[0], &C[strlen(C)-1]);
	for(auto &i:L){
		cout << L;
	}
}
