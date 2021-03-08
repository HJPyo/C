#include<stdio.h>
#define max(x,y) (x > y ? x : y)

int n, k, ar[55];

int bit_cnt(int bit)
{
	int cnt = 0;
	while(bit){
		cnt += (bit & 1);
		bit >>= 1;
	}
	return cnt;
}

int f(int x, int cnt, int bit)
{
	if(bit_cnt(bit) > k) return 0;
	if(x == n) return cnt;
	
	return max(f(x+1,cnt,bit),f(x+1,cnt+1,bit|ar[x]));
}

int main()
{
	scanf("%d %d", &n, &k);
	k -= 5;
	
	for(int i = 0; i < n; i++){
		char tmp[20];
		scanf("%s", &tmp);
		for(int j = 0; tmp[j] != NULL; j++){
			char now = tmp[j];
			if(now == 'a' || now == 'n' || now == 't' || now == 'i' || now == 'c') continue;
			ar[i] |= 1 << (now - 'a');
		}
	}
	
	printf("%d", f(0,0,0));
}
