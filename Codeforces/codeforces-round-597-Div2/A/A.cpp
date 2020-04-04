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

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int T, A, B;
    cin >> T;

    while(T--) {
        cin >> A >> B;
        if(__gcd(A,B) == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }

    return 0;
}

