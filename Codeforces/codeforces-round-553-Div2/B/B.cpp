#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 500 + 5;
int const maxa = 1023 + 1;
int V[maxn][maxn];
map<int, int> vis[maxn];
int ans[maxn];
int N, M;

int dfs(int x, int i) {
    if(!x) return false;
    if(i==N) return true;
    for(int k=0; k<M; ++k) {
        int a = V[i][k];
        ans[i] = k;

        if(vis[i].count(a)) continue;

        if(i) x ^= a;
        else x = a;
        vis[i][a] = 1;

        if(dfs(x, i+1)) return true;

        if(i) x ^= a;
    }
    vis[i].clear();
    return false;
}

void printAns() {
    for(int i=0; i<N; ++i) {
        if(i) cout << " ";
        cout << ans[i] + 1;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            cin >> V[i][j];
            vis[i][j] = 0;
        }
    }

    if(!dfs(-1, 0)) cout << "NIE";
    else {
        cout << "TAK" << endl;
        printAns();
    }

    return 0;
}

