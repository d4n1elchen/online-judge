#include<bits/stdc++.h>
#define CORN     1 // 001
#define KIILITOU 2 // 010
#define WOLF     4 // 100
using namespace std;
typedef long long LL;
typedef tuple<int, int, int> TII;

int const maxn=1000;
int cnt[maxn];
queue<TII> Q;

void bfs(int N) {
    int sstate, // South state
        nstate, // North state
        n;      // Step count
    Q.emplace(7, 0, 0);
    while(!Q.empty()) {
        tie(sstate, nstate, n) = Q.front(); Q.pop();
        /* printf("(%d, %d, %d)\n", sstate, nstate, n); */
        if(nstate==7) {
            ++cnt[n];
        } else if(n<N) {
            ++n;
            for(int i=1; i<8; i<<=1) {
                if((n&1)
                        && (sstate&i)
                        && (sstate-i)!=3 && (sstate-i)!=6) // ->
                    Q.emplace(sstate-i, nstate+i, n);
                else if(!(n&1)
                        && (nstate&i)
                        && (nstate-i)!=3 && (nstate-i)!=6) // <-
                    Q.emplace(sstate+i, nstate-i, n);
            }
            // Empty ship
            if(((n&1) && sstate!=7 && sstate!=3 && sstate!=6)           // ->
                    || (!(n&1) && nstate!=7 && nstate!=3 && nstate!=6)) // <-
                Q.emplace(sstate, nstate, n);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    memset(cnt, 0, sizeof(cnt));

    int N;
    cin >> N;
    bfs(N);
    for(int i=1; i<=N; ++i) {
        cout << cnt[i] << endl;
    }

    return 0;
}

