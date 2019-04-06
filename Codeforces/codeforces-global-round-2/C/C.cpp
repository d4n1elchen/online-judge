#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 505;
int A[maxn][maxn], B[maxn][maxn];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin >> A[i][j];
    for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin >> B[i][j];

    for(int i=0; i<N; ++i) {
        int cnt=0;
        for(int j=0; j<M; ++j) if(A[i][j]^B[i][j]) ++cnt;
        if(cnt&1) { cout << "No"; return 0; }
    }
    for(int j=0; j<M; ++j) {
        int cnt=0;
        for(int i=0; i<N; ++i) if(A[i][j]^B[i][j]) ++cnt;
        if(cnt&1) { cout << "No"; return 0; }
    }
    cout << "Yes";

    return 0;
}

