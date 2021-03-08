#include<stdio.h>
#include<algorithm>
using namespace std;

int n, ar[55], idx;

bool IsSorted()
{
	for(int i = 0; i < n-1; i++){
		if(ar[i]+1 == ar[i+1]){
			idx = i+1;
			return true;
		}
	}
	return false;
}

void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	sort(ar,ar+n);
	
	while(IsSorted()){
		int c_idx = 0;
		while(ar[idx] == ar[c_idx]) c_idx++;
		
		swap(ar[idx], ar[c_idx]);
		/*
		for(int i = 0; i < n; i++){
			printf("%d ", ar[i]);
		}
		puts("");
		*/
	}
	
	for(int i = 0; i < n; i++){
		printf("%d ", ar[i]);
	}
}
