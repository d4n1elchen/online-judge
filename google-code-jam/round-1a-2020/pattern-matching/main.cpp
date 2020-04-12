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

vector<string> P;
vector<uint> Pi;

bool isAllEnd()
{
    for(int i=0; i<N; ++i) {
        if(Pi[i] != P.size()) return false;
    }
    return true;
}

void solve()
{
    cin >> N;
    P.resize(N);
    Pi.resize(N);
    fill(Pi.begin(), Pi.end(), 0);
    for(int i=0; i<N; ++i) {
        cin >> P[i];
    }
    string res = "";
    while(!isAllEnd()) {
        for(int i=0; i<N; ++i) {
            if(P[i][Pi[i]] == '*') {
                Pi[i]++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> T;

    int i = 1;
    while(T--) {
        cout << "Case #" << i;
        solve();
    }

    return 0;
}

