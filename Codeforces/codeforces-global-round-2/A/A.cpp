#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 300003;
int C[maxn];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, ans, i;

    cin >> N;
    for(i=0; i<N; ++i) {
        cin >> C[i];
    }

    for(i=0; i<N/2; ++i) {
        if((C[i]!=C[N-1]) || (C[0]!=C[N-1-i])) break;
    }
    cout << N-1-i;

    return 0;
}

