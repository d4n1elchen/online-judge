#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 200009;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, p = 0, a, cnt_h = 0, cnt = 0, cnt_max = 0;

    cin >> N;

    for(int n=0; n<N; ++n) {
        cin >> a;
        if(p == 0 && a == 1) ++cnt_h;
        else if(p == 0 && a == 0) p = 1;

        if(p == 1 && a == 1) {
            ++cnt;
            if(cnt > cnt_max) cnt_max = cnt;
        } else if(p == 1 && a == 0) {
            cnt = 0;
        }
    }

    if((cnt_h + cnt) > cnt_max) cnt_max = cnt_h + cnt;
    cout << cnt_max;

    return 0;
}

