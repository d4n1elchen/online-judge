#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 100005;
LL A[maxn];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    LL N, a, b;
    LL sum = 0;
    cin >> N;

    for(int i=0; i<N; ++i) {
        cin >> a >> b;
        A[i] = a - b;
        sum += b*N - a;
    }
    sort(A, A+N, greater<LL>());
    for(int i=0; i<N; ++i) {
        sum += A[i]*(i+1);
    }
    cout << sum;

    return 0;
}

