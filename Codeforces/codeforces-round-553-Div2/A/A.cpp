#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 55;
int S[maxn];
int gn[4] = {0, 2, 19, 6};

int steps(int s) {
    int sum=0, p;
    for(int i=0; i<4; ++i) {
        p = abs(S[s+i]-gn[i]);
        sum += min(p, 26-p);
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N; char c;
    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> c;
        S[i] = c - 'A';
    }
    int mi=9e5;
    for(int i=0; i<N-3; ++i) {
        mi = min(mi, steps(i));
    }
    cout << mi;

    return 0;
}

