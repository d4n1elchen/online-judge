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
int M[200][200];

bool checkRow(int r)
{
    vector<bool> ch(N, false);
    for(int i=0; i<N; ++i) {
        if(ch[M[r][i]]) return false;
        else ch[M[r][i]] = true;
    }
    return true;
}

bool checkCol(int c)
{
    vector<bool> ch(N, false);
    for(int i=0; i<N; ++i) {
        if(ch[M[i][c]]) return false;
        else ch[M[i][c]] = true;
    }
    return true;
}

void solve()
{
    int k=0, c=0, r=0;
    cin >> N;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> M[i][j];
            if(i==j) k += M[i][j];
        }
        if(!checkRow(i)) r++;
    }
    for(int i=0; i<N; ++i) {
        if(!checkCol(i)) c++;
    }
    printf("%d %d %d\n", k, r, c);
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

