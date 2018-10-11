#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

vector<lli> v;

int main()
{
    lli n, k,
        x_min=1<<30,
        sum=0,
        c, cost=0,
        res=0;

    int cnt=0;

    cin >> n >> k;
    v.resize(n);
    for (lli i=0; i<n; ++i)
    {
        cin >> v[i];
        if (v[i] < x_min) x_min = v[i];
        sum += v[i];
    }
    sum -= x_min * n;
    if (sum > 0) {
        sort(v.begin(), v.end(), greater<lli>());
        for (lli i=1; i<v.size(); ++i)
        {
            c = v[i-1] - v[i];
            if ((cost + c * i) > k)
            {
                res = (k - cost) / i;
                sum -= cost + res * i;
                cnt++;
                while ((c -= res) * i > k)
                {
                    res = k / i;
                    sum -= res * i;
                    cnt++;
                }
                if (sum <= 0) break;
                cost = 0;
            }
            cost += c * i;
        }
    }
    if (sum > 0) cnt++;
    cout << cnt;
}
