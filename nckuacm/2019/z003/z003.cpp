#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    LL k, x;
    cin >> N;
    while(N--) {
        cin >> k >> x;
        cout << (k - 1) * 9 + x << endl;
    }
}
