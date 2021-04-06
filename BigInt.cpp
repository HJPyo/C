#include <stdio.h>
#include <math.h>

#define ll long long
#define CIPHER_CNT 18
static const ll CIPHER = pow(10, CIPHER_CNT);

typedef struct _tagBigInteger {
    ll high;
    ll low;
} BI;

BI ll_to_bi(ll li) {
    return {0, li};
}

BI bi_add_bi(BI a, BI b) {
    ll tlow = a.low % CIPHER + b.low % CIPHER;
    ll thigh = 0;
    if (tlow % CIPHER != a.low + b.low) {
        thigh = a.low / CIPHER + b.low / CIPHER;
    }
    thigh += a.high + b.high;
    return {thigh, tlow};
}

int main() {
    ll ta;
    ll tb;
    BI A;
    BI B;
    BI result;
    scanf("%lld %lld", &ta, &tb);
    A = ll_to_bi(ta);
    B = ll_to_bi(tb);
    result = bi_add_bi(A, B);
    printf("%lld%018lld\n", result.high, result.low);
    return 0;
}
