#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for(int t=1; t<=T; ++t) {
        cout << "Case #" << t << ": ";
        int N; char c;
        cin >> N;
        for(int i=0; i<(N-1)*2; ++i) {
            cin >> c;
            if(c=='S') cout << 'E';
            else cout << 'S';
        }
        cout << endl;
    }

    return 0;
}

