#include<stdio.h>

int n, k, gate[100005], air[100005];

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < k; i++){
		scanf("%d", &air[i]);
	}
	
	int cnt = 0;
	
	for(int i = 0; i < k; i++){
		while(gate[air[i]] > 0){
			air[i]--;
			if(air[i] == 0) goto END;
		}
		gate[air[i]] = 1;
		cnt++;
	}
	
	END:
	
	printf("%d", cnt);
}
