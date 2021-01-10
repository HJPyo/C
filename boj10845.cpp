#include<stdio.h>

int n, Q[10001], Qsize = 0;

void q_push(int x){
	if(Qsize){
		for(int i=Qsize; i>0; i--)
		Q[i] = Q[i-1];
	}
	Q[0] = x;
	Qsize++;
}

void q_pop(){
	printf("%d\n", Qsize ? Q[--Qsize] : -1);
}

void q_size(){
	printf("%d\n", Qsize);
}

void q_empty(){
	printf("%d\n", Qsize>0 ? 0 : 1);
}

void q_front(){
	printf("%d\n", Qsize>0 ? Q[Qsize-1] : -1);
}

void q_back(){
	printf("%d\n", Qsize>0 ? Q[0] : -1);
}

int chk(char* ar){
	if(ar[0] == 'p'){
		if(ar[1] == 'u') return 0;
		else return 1;
	}
	else if(ar[0] == 's') return 2;
	else if(ar[0] == 'e') return 3;
	else if(ar[0] == 'f') return 4;
	else return 5;
}

int main()
{
	scanf("%d", &n);
	while(n--){
		char ar[10];
		scanf("%s", &ar);
		int query = chk(ar), X;
		if(query == 0) scanf("%d", &X);
		
		switch(query){
			case 0:{ q_push(X); break; }
			case 1:{ q_pop(); break; }
			case 2:{ q_size(); break; }
			case 3:{ q_empty(); break; }
			case 4:{ q_front(); break; }
			case 5:{ q_back(); break; }
		}
	}
}
