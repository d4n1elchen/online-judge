#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<LL, LL> PLL;

vector<PLL> segs;
vector<PLL> segs_next;

int main()
{
    int T;
    LL N, K, li, ri, len, max_len;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld %lld", &N, &K);
        segs.resize(N);
        for(LL n = 0; n < N; n++) {
            scanf("%lld %lld", &li, &ri);
            segs[n] = make_pair(li, ri);
        }
        sort(segs.begin(), segs.end(), [](const PLL &l, const PLL &r) {
                    return l.first < r.first;
                });
        for(LL k = 0; k < K-1; k++) {
            segs_next.clear();
            max_len = 0;
            for(LL n = 1; n < (LL)segs.size(); n++) {
                PLL seg1 = segs[n-1];
                PLL seg2 = segs[n];
                if(seg2.first <= seg1.second) {
                    LL fi, se;
                    fi = seg2.first;
                    se = min(seg1.second, seg2.second);
                    segs_next.push_back(make_pair(fi, se));
                    len = se - fi;
                    if(len > max_len) max_len = len;
                }
            }
            segs.assign(segs_next.begin(), segs_next.end());
        }
        printf("%lld\n", max_len);
    }
}
