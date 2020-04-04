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

VI A, D;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, L, R, K;
    cin >> N >> L >> R >> K;

    A.resize(N, 0);
    for(int i=0; i<N; ++i) {
        cin >> A[i];
    }

    int d = A[1] - A[0], cnt = 1;
    for(int i=2; i<N; ++i) {
        if(d == 0) {
            D.push_back(0);
            cnt = 1;
            d = A[i] - A[i-1];
            continue;
        }
        if((A[i]-A[i-1]) * d > 0) {
            cnt++;
        }
        else {
            if(d<0) D.push_back(-cnt);
            else if(d>0) D.push_back(cnt);
            cnt = 1;
        }
        d = A[i] - A[i-1];
    }

    int r = R - A[0], a = A[0];
    for(int i=0; i<D.size(); ++i) {
        if(D[i] > r) {
            cout << -1;
            return 0;
        }
        if(D[i] > 0) {
            a += D[i];
            r -= D[i];
        }
        else if(D[i] < 0) {
        }
    }

    return 0;
}

