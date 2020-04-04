#include<bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef vector<LL> VL;
typedef vector<int> VI;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int T, N, M, Q, p, r;

    cin >> T;
    for(int t=1; t<=T; ++t) {
        cin >> N >> M >> Q;
        VI cnt(N+1, 0);
        cnt[1] = M;
        for(int i=0; i<M; ++i) {
            cin >> p;
            if(p>1) cnt[p]++;
            for(int j=2; j*j<=p; ++j) {
                if(p%j == 0) {
                    cnt[j]++;
                    if(p/j != j) cnt[p/j]++;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<Q; ++i) {
            cin >> r;
            /* cout << r <<","<<N/r<<","<<cnt[r]<<endl; */
            ans += N/r - cnt[r];
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}

