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

int T, X, Y;
string s;
unordered_map<char, PII> M;

void solve()
{
    cin >> X >> Y;
    cin >> s;
    int cnt = 0;
    for(char c: s) {
        cnt++;
        PII p = M[c];
        if((abs(X + p.st) > abs(X)) || (abs(Y + p.nd) > abs(Y))) {
        } else if((abs(X + p.st) < abs(X))) {
            X += p.st;
            if(abs(Y) > 0) {
                Y += (Y < 0)? 1: -1;
            } else if(abs(X) > 0) {
                X += (X < 0)? 1: -1;
            }
        } else if((abs(Y + p.nd) < abs(Y))) {
            Y += p.nd;
            if(abs(X) > 0) {
                X += (X < 0)? 1: -1;
            } else if(abs(Y) > 0) {
                Y += (Y < 0)? 1: -1;
            }
        } else {
            X += p.st;
            Y += p.nd;
        }
        /* cout << c << ":" << X << "," << Y << endl; */
        if(Y==0 && X==0) {
            break;
        }
    }
    if(Y==0 && X==0) {
        cout << cnt << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> T;
    int i = 1;
    M['N'] = make_pair(0, 1);
    M['S'] = make_pair(0, -1);
    M['W'] = make_pair(-1, 0);
    M['E'] = make_pair(1, 0);
    while(T--) {
        cout << "Case #" << i++ << ": ";
        solve();
    }

    return 0;
}

