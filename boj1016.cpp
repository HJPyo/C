#include<stdio.h>
#define LL long long int
#define I (i*i)

int sum = 0;
LL min, max;
int ar[1111111];

int main()
{
    scanf("%lld %lld", &min, &max);
    for(LL i = 2; I <= max; i++){
        for(LL j = min/I; j*I <= max; j++){
            if(j*I < min) continue;
			if(!ar[j*I - min]){
                ar[j*I - min] = 1;
                sum++;
            }
        }
    }
    printf("%lld", (max-min+1)-sum);
}
