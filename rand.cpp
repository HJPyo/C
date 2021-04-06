#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	srand(time(NULL));
	printf(rand() & 1 ? "ธิพ๎" : "ธิม๖ธถ");
}
