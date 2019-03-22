#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 200005;
LL A[maxn], B[maxn];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    LL cnt = 0, curr;
    cin >> N;

    for(int i=0; i<N; ++i) cin >> A[i];
    curr = A[N-1];
    for(int i=N-1; i>=0; --i) {
        if (A[i] < curr) curr = A[i];
        cnt += curr;
        curr = curr - 1;
        if (curr < 0) break;
    }
    cout << cnt;

    return 0;
}
