#include<bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second
#define SS(_n, i, j) S[_n[i][j].first][_n[i][j].second]
#define NN(_t, _n, i, j) _t[_n[i][j].first][_n[i][j].second]

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef vector<LL> VL;
typedef vector<int> VI;

LL T, R, C;

int S[100005][100005];
vector<vector<PII>> Nl;
vector<vector<PII>> Nr;
vector<vector<PII>> Nu;
vector<vector<PII>> Nd;

bool eliminate(int i, int j)
{
    if(S[i][j] == 0) return false;
    if(S[i][j] * 4 < (SS(Nl, i, j) + SS(Nr, i, j) + SS(Nu, i, j) + SS(Nd, i, j))) {
        S[i][j] = 0;
        NN(Nl, Nr, i, j) = Nl[i][j];
        NN(Nr, Nl, i, j) = Nr[i][j];
        NN(Nu, Nd, i, j) = Nu[i][j];
        NN(Nd, Nu, i, j) = Nd[i][j];
        return true;
    }
    return false;
}

void solve()
{
    cin >> R >> C;

    memset(S, 0, sizeof(S));
    Nl.clear();
    Nr.clear();
    Nu.clear();
    Nd.clear();

    Nl.resize(R);
    Nr.resize(R);
    Nu.resize(R);
    Nd.resize(R);
    for(int i=0; i<R; ++i) {
        Nl[i].resize(C);
        Nr[i].resize(C);
        Nu[i].resize(C);
        Nd[i].resize(C);
        for(int j=0; j<C; ++j) {
            cin >> S[i][j];
            if(i-1 >= 0) Nd[i][j] = make_pair(i-1, j);
            if(i+1 <  R) Nu[i][j] = make_pair(i+1, j);
            if(j-1 >= 0) Nl[i][j] = make_pair(i, j-1);
            if(j+1 <  C) Nr[i][j] = make_pair(i, j+1);
        }
    }

    LL cnt=1, rsum=0, csum=0;
    while(cnt)
    {
        cnt = 0;
        rsum = 0;
        for(int i=0; i<R; ++i) {
            for(int j=0; j<C; ++j) {
                cnt += eliminate(i, j);
                rsum += S[i][j];
            }
        }
        csum += rsum;
    }

    cout << csum << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> T;

    int i = 1;
    while(T--) {
        cout << "Case #" << i++ << ": ";
        solve();
    }

    return 0;
}

