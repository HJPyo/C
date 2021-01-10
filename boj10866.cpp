#include<stdio.h>

class DequeContainer{
	public:
		int ar[10001] = {}, DqSize = 0;
		
		void Push_F(int x)
		{
			if(DqSize > 0){
				for(int i = DqSize++; i > 0; i--)
				ar[i] = ar[i-1];
			}
			ar[0] = x;
		}
		
		void Push_B(int x)
		{
			ar[DqSize++] = x;
		}
		
		void Pop_F()
		{
			if(DqSize-- == 0){
				printf("-1\n");
				break;
			}
			printf("%d\n", ar[0]);
			for(int i = 0; i < DqSize; i++){
				
			}
		}
};

int main()
{
	
}
