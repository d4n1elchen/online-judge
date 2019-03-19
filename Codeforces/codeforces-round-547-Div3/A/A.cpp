#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    LL m, n, r, q, cnt;

    cin >> n >> m;

    r = m % n;
    if (r) {
        cout << "-1";
        return 0;
    }
    q = m / n;

    cnt = 0;
    while (!(q % 3)) {
        q /= 3;
        ++cnt;
    }
    while (!(q % 2)) {
        q /= 2;
        ++cnt;
    }

    if (q != 1) cout << "-1";
    else cout << cnt;

    return 0;
}

