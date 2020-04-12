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

LL T, N;

vector<PII> path;
int visited[600][600];

int dr[6] = {-1, -1, 0, 0, 0, 1};
int dk[6] = {-1, 0, -1, 1, 0, 1};

LL nextp(LL pn, int r, int k, int i)
{
    //cout << pn << ":" << r << "," << k << "/" << i << endl;
    switch(i) {
        case 0:
            return pn * k / r;
        case 1:
            return pn * (r-k) / r;
        case 2:
            return pn * k / (r-k+1);
        case 3:
            return pn * (r-k) / (k+1);
        case 4:
            return pn * (r+1) / (r-k+1);
        case 5:
            return pn * (r+1) / (k+1);
    }
    return pn;
}

bool bt(int r, int k, LL pn, int lvl, LL sum)
{
    if(lvl > 500 || sum > N) return false;
    if(sum == N) return true;
    //cout << r << "," << k << "," << pn << "," << lvl << "," << sum << "," << N << endl;
    int nr, nk;
    LL npn;
    for(int i=0; i<6; ++i) {
        nr = r + dr[i];
        nk = k + dk[i];
        //cout << nr << "," << nk << endl;
        if(nr >= 0 && nk >= 0 && nk <= nr && !visited[nr][nk]) {
            npn = nextp(pn, r, k, i);
            path.emplace_back(nr, nk);
            visited[nr][nk] = 1;
            if(bt(nr, nk, npn, lvl+1, sum+npn)) {
                return true;
            }
            visited[nr][nk] = 0;
            path.pop_back();
        }
    }
    return false;
}

void solve()
{
    cin >> N;
    cout << endl;
    path.clear();
    memset(visited, 0, sizeof(visited));
    path.emplace_back(0, 0);
    visited[0][0] = 1;
    bt(1, 0, 1, 1, 1) || bt(1, 1, 1, 1, 1);
    // print path
    for(uint i=0; i<path.size(); ++i) {
        cout << path[i].st+1 << " " << path[i].nd+1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> T;

    int i = 1;
    while(T--) {
        cout << "Case #" << i++ << ":";
        solve();
    }

    return 0;
}

