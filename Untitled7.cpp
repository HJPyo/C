#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	while(n--){
		int chk = 0;
		char _[55];
		scanf("%s", &_);
		for(int i = 0; _[i] != NULL; i++){
			if(chk < 0){ chk = 1; break; }
			if(_[i] == '(') chk++;
			else chk--;
		}
		if(chk) puts("NO");
		else puts("YES");
	}
}
