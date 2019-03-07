#include<bits/stdc++.h>
typedef long long LL;

LL cnt[200001];

int main() {
    LL i, j, n, k, h, minh, maxh, tmpk, slice, unit, tmpi;
    scanf("%lld%lld", &n, &k);
    memset(cnt, 0, sizeof(LL) * 200001);
    minh = 10000000;
    maxh = -1;
    for (i = 0; i < n; ++i) {
        scanf("%lld", &h);
        ++cnt[h];
        if (h > maxh) maxh = h;
        if (h < minh) minh = h;
    }
    slice = 0;
    tmpk = k;
    for (i = maxh; i > minh; ) {
        for (j = i-1; j > minh && cnt[j] == 0; --j);
        if (cnt[i] * (i-j) >= tmpk) {
            unit = tmpk / cnt[i];
            tmpi = i - unit;
            if(tmpi != i) cnt[tmpi] += cnt[i];
            i = tmpi;
            tmpk = k;
            ++slice;
        }
        else {
            tmpk -= cnt[i] * (i-j);
            cnt[j] += cnt[i];
            i = j;
            if(i == minh) ++slice;
        }
    }
    printf("%lld\n", slice);
}
