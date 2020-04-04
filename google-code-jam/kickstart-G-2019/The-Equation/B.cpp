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

LL const INF = 1e15;

VL A;

LL maxdigit(LL M) {
    LL cnt = 0;
    while(M) {
        cnt++;
        M >>= 1;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    LL T, M, N;

    /* int K=15; */
    /* for(int i=-K; i<=K; ++i) { */
    /*     for(int j=-K; j<=K; ++j) */
    /*         printf("%3d ", i^j); */
    /*     printf("\n"); */
    /* } */

    LL ma, mi;
    cin >> T;
    for(int t=1; t<=T; ++t) {
        ma = 0; mi = INF;
        cin >> N >> M;
        A.resize(N);
        for(int i=0; i<N; ++i) {
            cin >> A[i];
            ma = max(A[i], ma);
            mi = min(A[i], mi);
        }
        LL sum, k;
        for(k=ma<<1; k>=0; --k) {
            sum = 0;
            for(auto a: A) sum += a^k;
            if(sum <= M) break;
        }
        cout << "Case #" << t << ": " << k << endl;
    }

    return 0;
}

