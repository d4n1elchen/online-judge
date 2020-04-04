#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N;

    vector<vector<LL>> table(N, vector<LL>(N, 0));
    vector<LL> ans(N, 0);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> table[i][j];
        }
    }

    ans[0] = sqrt(table[0][1]*table[0][2]/table[1][2]) + 0.5;
    cout << ans[0];
    for(int i=1; i<N; ++i) {
        cout << " " << table[0][i] / ans[0];
    }

    return 0;
}

