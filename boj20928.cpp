#include<stdio.h>
#define MAX 1000005

int n, k;
int pos[MAX], val[MAX];

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &pos[i]);
	}
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &val[i]);
	}
	
	int idx = k, now = n, cnt = 0;
	
	while(idx != 1){
		while(pos[now] + val[now] < idx || pos[now] > idx){
			if(!now){
				cnt = -1;
				goto END;
			}
			now--;
			cnt++;
		}
		idx--;
	}
	
	END:
	
	printf("%d", cnt);
}
