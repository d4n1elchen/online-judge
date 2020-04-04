#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N; char c;
    cin >> N;
    vector<int> ans;

    for(int i=0; i<N; ++i) {
        cin >> c;
        if(c == 'z') ans.push_back(0);
        if(c == 'n') ans.push_back(1);
    }
    sort(ans.begin(), ans.end(), greater<int>());

    bool ps = false;
    for(auto d : ans) {
        cout << (ps? " ": "") << d;
        ps = true;
    }

    return 0;
}

