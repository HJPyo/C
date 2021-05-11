#include<stdio.h>

int n, m;

int gcd(int x, int y){
    return y ? gcd(y, x%y) : x;
}

int main(){
    scanf("%d %d", &n, &m);
    printf("%d", gcd(n,m));
}