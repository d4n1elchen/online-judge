#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

set<int> ss;
string s;

bool diverse() {
    bool ok=true;
    if(s.size() != ss.size()) ok=false;
    for(auto curr=(++ss.begin()), prev=ss.begin(); curr!=ss.end(); ++curr, ++prev) {
        if(*curr != *prev+1)  {
            ok=false;
        }
    }
    return ok;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N;

    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> s;
        ss.clear();
        for(size_t j=0; j<s.size(); ++j) {
            ss.insert(s[j]);
        }
        if(diverse()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

