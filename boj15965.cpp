#include<stdio.h>
#include<vector>
#define MAX 7654321
using namespace std;

int n, ar[MAX];
vector<int>v;

int main()
{
	v.push_back(0);
	for(int i = 2; i < MAX; i++){
		if(ar[i] == 0){
			for(int j = i << 1; j < MAX; j += i){
				ar[j] = 1;
			}
			v.push_back(i);
		}
	}
	scanf("%d", &n);
	printf("%d", v[n]);
}
