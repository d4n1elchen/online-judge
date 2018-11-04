#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

LL const MOD = 1000000007;
int const maxs = 1e6 + 10;

int N, S, cnt[maxs];

LL sameskill(int n) {
    LL res = (n&1)? n : (n-1);
    for(LL i = n-2; i >= 1; i--) {
        res = (res * i) % MOD;
    }

    return res;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(cnt, 0, sizeof(cnt));

        scanf("%d", &N);
        for(int i = 0; i < N; i++) {
            scanf("%d", &S);
            cnt[S]++;
        }

        LL pro = 1;
        LL sum = 0;
        for(int i = maxs - 1; i >= 0; i--) {
            if(cnt[i]) {
                LL nofriend = sum&1;
                pro = ((nofriend? cnt[i]: 1) * pro * sameskill(cnt[i] - nofriend)) % MOD;
                sum += cnt[i];
            }
        }

        printf("%lld\n", pro);
    }

    return 0;
}
