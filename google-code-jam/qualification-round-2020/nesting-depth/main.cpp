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

int T, N;
string S;
VI v;
VI l, r;

void solve()
{
    cin >> S;
    N = S.size();
    v.resize(N);
    l.resize(N);
    r.resize(N);
    int ma=0;
    for(int i=0; i<N; ++i) {
        v[i] = S[i]-'0';
        l[i] = 0;
        r[i] = 0;
        ma = max(ma, v[i]);
    }
    for(int n=ma; n>0; --n) {
        for(int i=0; i<N; ++i) {
            if(v[i] == n) {
                l[i]++;
                v[i]--;
                while(i+1 < N && v[i+1] == n) {
                    v[++i]--;
                }
                r[i]++;
            }
        }
    }
    for(int i=0; i<N; ++i) {
        for(int k=0; k<l[i]; k++) printf("(");
        printf("%c", S[i]);
        for(int k=0; k<r[i]; k++) printf(")");
    }
    puts("");
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> T;

    int i=1;
    while(T--) {
        printf("Case #%d: ", i++);
        solve();
    }

    return 0;
}

