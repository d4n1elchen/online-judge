#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int a, ans, cur;
    cin >> a;

    cur = a&1; ans = cur;
    cout << cur << endl;
    for(int i=8; i>=0; i>>=1) {
        cur ^= a&1;
        cout << cur << endl;
        ans += cur*i;
    }
    cout << ans << endl;

    return 0;
}

