#include<bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef vector<LL> VL;
typedef vector<int> VI;

LL const MOD = 1e9+7;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int cnt=0;
    char curr;
    string s;
    cin >> s;
    VLL dp(s.size(), 0);
    dp[0] = 1;

    for(int i=0; i<s.size(); ++i) {
        if(c == 'm' || c == 'w') { cout << 0; return 0; }
        dp[i+1] = dp[i];

    }

    return 0;
}

