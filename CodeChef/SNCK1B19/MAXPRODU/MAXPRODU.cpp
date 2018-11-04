#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL const MOD = 1000000007;

int main()
{
    int T;
    LL N, K, prod, mi_valid, mean, rem;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld %lld", &N, &K);
        mi_valid = K * (K + 1) / 2;
        if(N < mi_valid) {
            prod = -1;
        } else {
            prod = 1;
            mean = (N - mi_valid) / K;
            rem = (N - mi_valid)%K;
            for(LL x = mean+K; x >= mean+1; x--) {
                LL y = x + ((rem > 0)? 1 : 0);
                prod = (prod * ((y*(y-1))%MOD))%MOD;
                rem--;
            }
        }
        printf("%lld\n", prod);
    }
}
