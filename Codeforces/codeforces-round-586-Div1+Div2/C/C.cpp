#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;

    int N = s.size();
    vector<int> cnt(26, 0);
    for(int i=0; i<N; ++i) {
        int n = s[i]-'a';
        bool awin = false;
        cnt[n]++;
        if(n) for(int j=n-1; j>=0; --j) if(cnt[j]) awin = true;
        cout << (awin? "Ann" : "Mike") << endl;
    }

    return 0;
}

