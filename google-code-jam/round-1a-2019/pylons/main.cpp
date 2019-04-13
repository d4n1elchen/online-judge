#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int const maxn = 25;
int R, C;
int board[maxn][maxn];
vector<PII> path;

void Init() {
    path.clear();
    for(int i=0; i<R; ++i) for(int j=0; j<C; ++j) board[i][j] = 0;
}

bool isSafe(int rl, int cl, int rn, int cn) {
    return !board[rn][cn] && (rl != rn) && (cl != cn) && ((rl-cl) != (rn-cn)) && ((rl+cl) != (rn+cn));
}

bool solve(int rl, int cl) {
    if(path.size() == R*C) return true;
    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
            if(isSafe(rl, cl, i, j)) {
                path.emplace_back(i, j);
                board[i][j] = 1;
                if(solve(i, j)) return true;
                board[i][j] = 0;
                path.pop_back();
            }
        }
    }
    return false;
}

void printPath() {
    cout << "POSSIBLE" << endl;
    for(auto p : path) {
        cout << p.first+1 << " " << p.second+1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for(int t=1; t<=T; ++t) {
        cout << "Case #" << t << ": ";
        cin >> R >> C;
        Init();
        int solved=false;
        for(int i=0; i<R; ++i) {
            for(int j=0; j<C; ++j) {
                solved=solve(i, j);
                if(solved) {
                    printPath();
                    break;
                }
            }
            if(solved) break;
        }
        if(!solved) cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

