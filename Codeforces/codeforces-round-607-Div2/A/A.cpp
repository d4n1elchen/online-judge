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

    regex filip(".*po$");
    regex japan(".*(de|ma)su$");
    regex korea(".*mnida$");

    int T;
    string s;

    cin >> T;
    while(T--) {
        cin >> s;
        if(regex_match(s, filip)) {
            cout << "FILIPINO" << endl;
            continue;
        }
        if(regex_match(s, japan)) {
            cout << "JAPANESE" << endl;
            continue;
        }
        if(regex_match(s, korea)) {
            cout << "KOREAN" << endl;
            continue;
        }
    }

    return 0;
}

