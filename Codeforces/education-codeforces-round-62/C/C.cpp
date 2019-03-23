#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

bool comp(PLL a, PLL b) { return a.second < b.second; }

vector<PLL> all;
priority_queue<PLL, vector<PLL>, greater<PLL>> lst;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    LL N, t, b, sum=0, ma=0;
    unsigned long long k;
    PLL p;
    cin >> N >> k;
    for(LL i=0; i<N; ++i) {
        cin >> t >> b;
        all.push_back(make_pair(t, b));
    }
    sort(all.begin(), all.end(), comp);

    for(LL i=N; i>0; --i) {
        p = all.back(); all.pop_back();
        sum += p.first;
        lst.push(p);
        if(lst.size() > k) { sum -= lst.top().first; lst.pop(); }
        ma = max(ma, sum*p.second);
    }

    cout << ma;

    return 0;
}

