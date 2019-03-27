#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 1000006;
int LAN[maxn];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, T, lan, b_idx;
    cin >> N;
    for(int i=0; i<N; ++i)
        cin >> LAN[i];
    sort(LAN, LAN+N);
    cin >> T;
    while(T--) {
        cin >> lan;
        b_idx = lower_bound(LAN, LAN+N, lan) - LAN;
        if(LAN[b_idx]==lan) cout << LAN[b_idx] << endl;
        else if(b_idx==N) cout << LAN[N-1] << " no" << endl;
        else if(b_idx==0) cout << "no " << LAN[0] << endl;
        else cout << LAN[b_idx-1] << " " << LAN[b_idx] << endl;
    }

    return 0;
}

