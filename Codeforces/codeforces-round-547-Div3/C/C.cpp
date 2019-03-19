#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 200005;
LL Q[maxn];
map<LL, int> check;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    LL N, sum=0, rsum, a1;
    memset(Q, 0, sizeof(Q));

    cin >> N;
    rsum = N*(N+1)/2;
    Q[0] = 0;
    for(LL n=1; n<N; ++n) {
        cin >> Q[n];
        Q[n] += Q[n-1];
        sum += Q[n];
    }

    if ((rsum - sum) % N) {
        cout << -1;
        return 0;
    }

    a1 = (rsum - sum) / N;

    for(LL n=0; n<N; ++n) {
        Q[n] += a1;
        if (Q[n]<1 || Q[n]>N || check.count(Q[n]) > 0) {
            cout << -1;
            return 0;
        }
        check[Q[n]] = 1;
    }
    for(LL n=0; n<N-1; ++n) {
        cout << Q[n] << " ";
    }
    cout << Q[N-1];

    return 0;
}

