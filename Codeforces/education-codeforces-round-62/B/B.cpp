#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

char S[200];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int T, N, fcn, ecn;

    cin >> T;
    while(T--) {
        cin >> N;
        fcn = 0; ecn = 0;
        for(int i=0; i<N; ++i) {
            cin >> S[i];
        }
        for(int i=0; i<N; ++i)
            if(S[i] == '<') fcn++;
            else break;
        for(int i=N-1; i>=0; --i)
            if(S[i] == '>') ecn++;
            else break;
        if(fcn * ecn != 0) cout << (fcn < ecn ? fcn : ecn) << endl;
        else cout << 0 << endl;
    }

    return 0;
}

