#include<stdio.h>

int k;

int main()
{
	scanf("%d", &k);
	while(k--){
		char str[88] = {};
		scanf("%s", &str);
		
		int score = 0;
		int combo = 0;
		for(int i = 0; str[i] != NULL; i++)
		{
			if(str[i] == 'O')
			{
				combo++;
				score += combo;
			}
			else{
				combo = 0;
			}
		}
		printf("%d\n", score);
	}
}
