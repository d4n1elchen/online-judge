#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL cnt[101];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    memset(cnt, 0, sizeof(cnt));

    LL n, k, d, r, res=0;
    cin >> n >> k;

    for(int i=0; i<n; ++i) {
        cin >> d;
        r = d % k;
        ++cnt[r];
    }

    res += cnt[0] - cnt[0] % 2;

    for(int i=1; i<k; ++i) {
        if(i == k-i)
            res += cnt[i] - cnt[i] % 2;
        else
            res += min(cnt[i], cnt[k-i]);
    }

    cout << res;

    return 0;
}
