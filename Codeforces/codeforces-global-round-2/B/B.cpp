#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> V;

LL min_height(LL N) {
    LL h = 0, i;
    for(i=N-1; i>=0; i-=2) { h += V[i]; }
    return h;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    LL N, H, a, res;

    cin >> N >> H;
    for(LL i=0; i<N; ++i) {
        cin >> a;
        V.push_back(a);
        sort(V.begin(), V.end());
        if(min_height(i+1) <= H) res = i+1;
    }

    cout << res;

    return 0;
}

