#include<bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

int const MAXN = 100000 + 10;

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef vector<LL> VL;
typedef vector<int> VI;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    VI R(N, 0), C(N, 0);
    VI Rl(N, 0), Cl(N, 0);

    for(int i=0; i<N; ++i) cin >> R[i];
    for(int i=0; i<N; ++i) cin >> C[i];

    bool parityR = (R[N-1]&1);
    bool parityC = (C[N-1]&1);
    Rl[N-1] = N;
    Cl[N-1] = N;
    for(int i=N-2; i>=0; --i) {
        if(parityR == (R[i]&1)) Rl[i] = Rl[i+1];
        else Rl[i] = i+1;
        if(parityC == (C[i]&1)) Cl[i] = Cl[i+1];
        else Cl[i] = i+1;
        parityR = R[i]&1;
        parityC = C[i]&1;
    }

    /* for(int i=0; i<N; ++i) { */
    /*     cout << Rl[i] << "," << Cl[i] << endl; */
    /* } */

    int ra, ca, rb, cb;
    for(int i=0; i<Q; ++i) {
        cin >> ra >> ca >> rb >> cb;
        ra--; ca--; rb--; cb--;
        if(ra>rb) swap(ra, rb);
        if(ca>cb) swap(ca, cb);
        if(Rl[ra] > rb && Cl[ca] > cb) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

