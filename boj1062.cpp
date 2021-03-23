#include<stdio.h>

int n, k, ar[55];

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++){
		char tmp[22];
		scanf("%s", &tmp);
		
		for(int j = 0; tmp[j] != NULL; j++){
			int t = tmp[j];
			if(t == 'a' || t == 'n' || t == 't' || t == 'i' || t == 'c') continue;
			ar[i] |= (1 << (t-'a'));
		}
	}
	
	
}
