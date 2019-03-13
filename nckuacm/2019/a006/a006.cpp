#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;

vector<LL> a;
vector<LL> b;
map<PLL, LL> cnt;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    LL n, g, ma=0, cnt0=0;
    PLL p;
    cin >> n;

    a.resize(n);
    b.resize(n);
    for(LL i = 0; i < n; ++i) cin >> a[i];
    for(LL i = 0; i < n; ++i) cin >> b[i];

    for(LL i = 0; i < n; ++i) {
        if(a[i] == 0 && b[i] == 0) {
            ++cnt0;
            continue;
        }
        if((a[i] * b[i] < 0 && b[i] < 0) || (a[i] < 0 && b[i] < 0)) {
            a[i] = -a[i];
            b[i] = -b[i];
        }

        if(b[i] == 0) {
            p = make_pair(1, 0);
        }
        else if(a[i] != 0) {
            g = __gcd(a[i], b[i]);
            p = make_pair(a[i]/g, b[i]/g);
        }
        else continue;

        if(cnt.count(p)) ++cnt[p];
        else cnt[p] = 1;
        ma = max(ma, cnt[p]);
    }

    cout << ma + cnt0;

    return 0;
}
