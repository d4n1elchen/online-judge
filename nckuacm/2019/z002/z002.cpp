#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int cnt[2001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    LL N, a, ma=0;
    bool first=true;
    memset(cnt, 0, sizeof(cnt));
    cin >> N;
    while(N--) {
        cin >> a;
        cnt[a]++;
        ma = max(ma, a);
    }
    for(int i=ma; i>0; --i) {
        if(!cnt[i]) continue;
        for(int j=0; j<cnt[i]; ++j)
            if(first) {
                cout << i;
                first = false;
            }
            else {
                cout << " " << i;
            }
    }
}
