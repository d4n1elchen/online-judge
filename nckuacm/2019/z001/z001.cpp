#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, cnt=0, a, ma=0, mc=0;
    cin >> n;
    while(n--) {
        cin >> a;
        if(a > ma) {
            ma = a;
            cnt = 1;
        }
        else if(a == ma) {
            cnt++;
            mc = max(mc, cnt);
        }
        else {
            cnt = 0;
        }
    }
    cout << mc;
}
