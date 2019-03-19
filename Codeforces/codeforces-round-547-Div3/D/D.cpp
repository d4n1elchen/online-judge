#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

map<char, vector<int>> b1, b2;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, l, r, cnt=0;
    char c;
    cin >> N;

    for(int n=0; n<N; ++n) {
        cin >> c;
        b1[c].push_back(n+1);
    }
    for(int n=0; n<N; ++n) {
        cin >> c;
        b2[c].push_back(n+1);
    }

    for(int i=0; i<26; ++i) {
        c = char('a' + i);
        while(!b1[c].empty() && !b2[c].empty()) {
            l = b1[c].back(); b1[c].pop_back();
            r = b2[c].back(); b2[c].pop_back();

            b1['+'].push_back(l);
            b2['+'].push_back(r);
            ++cnt;
        }
        while(!b1['?'].empty() && !b2[c].empty()) {
            l = b1['?'].back(); b1['?'].pop_back();
            r = b2[c].back(); b2[c].pop_back();

            b1['+'].push_back(l);
            b2['+'].push_back(r);
            ++cnt;
        }
        while(!b1[c].empty() && !b2['?'].empty()) {
            l = b1[c].back(); b1[c].pop_back();
            r = b2['?'].back(); b2['?'].pop_back();

            b1['+'].push_back(l);
            b2['+'].push_back(r);
            ++cnt;
        }
    }
    while(!b1['?'].empty() && !b2['?'].empty()) {
        l = b1['?'].back(); b1['?'].pop_back();
        r = b2['?'].back(); b2['?'].pop_back();

        b1['+'].push_back(l);
        b2['+'].push_back(r);
        ++cnt;
    }

    cout << cnt << endl;
    for(int i=0; i<cnt; ++i)
        cout << b1['+'][i] << " " << b2['+'][i] << endl;

    return 0;
}

