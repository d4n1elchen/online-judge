#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;
vector<LL> v;

int main()
{
    int T;
    LL N, K, kths, cnt;

    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        v.resize(N);
        for(auto n = 0; n < N; ++n)
        {
            cin >> v[n];
        }
        sort(v.begin(), v.end(), greater<LL>());
        kths = v[K-1];
        cnt = K;
        for(LL i = K; i < N; ++i)
        {
            if(v[i] < kths) break;
            cnt++;
        }
        cout << cnt << endl;
    }
}
