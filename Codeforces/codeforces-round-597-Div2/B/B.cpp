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

    int T, N, a, b, c;
    string s;
    unordered_map<char, int> M;
    cin >> T;

    while(T--) {
        cin >> N;
        cin >> a >> b >> c;
        cin >> s;
        M['R']=0; M['P']=0; M['S']=0;
        for(int i=0; i<N; ++i) M[s[i]]++;
        int wa, wb, wc;
        wa = min(a, M['S']);
        wb = min(b, M['R']);
        wc = min(c, M['P']);
        if((wa+wb+wc) < (N+1)/2) cout << "NO\n";
        else {
            int ra, rb, rc;
            ra = a - wa;
            rb = b - wb;
            rc = c - wc;
            cout << "YES\n";
            for(int i=0; i<N; ++i) {
                switch(s[i]) {
                    case 'R':
                        if(b) { cout << 'P'; b--; }
                        else if(ra) { cout << 'R'; a--; ra--; }
                        else { cout << 'S'; c--; rc--; }
                        break;
                    case 'P':
                        if(c) { cout << 'S'; c--; }
                        else if(ra) { cout << 'R'; a--; ra--; }
                        else { cout << 'P'; b--; rb--; }
                        break;
                    case 'S':
                        if(a) { cout << 'R'; a--; }
                        else if(rb) { cout << 'P'; b--; rb--; }
                        else { cout << 'S'; c--; rc--; }
                        break;
                }
            }
            cout << endl;
        }
    }

    return 0;
}

