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

    int T;
    string s, c, t;
    char cs, cc;
    cin >> T;
    while(T--) {
        cin >> s >> c;
        bool ok = false;
        if(s < c) ok = true;

        t = s;
        sort(t.begin(), t.end());
        for(int i=0; i<s.size() && !ok; ++i) {
            if(s[i] > t[i]) {
                for(int j=i+1; j<s.size(); ++j) {
                    swap(s[i], s[j]);
                    if(s < c) {
                        ok = true;
                        break;
                    }
                    swap(s[i], s[j]);
                }
            }
        }

        if(ok) {
            cout << s << endl;
        }
        else {
            cout << "---" << endl;
        }
    }

    return 0;
}

