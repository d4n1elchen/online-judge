#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef map<LL, LL> MLL;

MLL cnt;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    LL n, a, psum, msum=0;
    cin >> n;

    for(LL i=0; i<n; ++i) {
        cin >> a;
        if(cnt.count(a)) ++cnt[a];
        else cnt[a] = 1;
    }

    for(MLL::iterator it = cnt.begin(); it != cnt.end(); ++it) {
        psum = it->second;
        for(MLL::iterator it2 = next(it); (it2->first - it->first) <= 5 && it2 != cnt.end(); ++it2) {
            psum += it2->second;
        }
        msum = max(msum, psum);
    }

    cout << msum;

    return 0;
}

