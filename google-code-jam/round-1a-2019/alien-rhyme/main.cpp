#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, char> PIC;
typedef pair<int, vector<string>> PIVS;

priority_queue<PIVS, vector<PIVS>, greater<PIVS>> PQ;
set<string> used;
map<PIC, vector<string>> M;

void Init() {
    used.clear();
    M.clear();
    while(!PQ.empty()) PQ.pop();
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, N; string w;
    cin >> T;
    for(int t=1; t<=T; ++t) {
        cout << "Case #" << t << ": ";
        cout << endl;
        cin >> N;
        Init();
        int cnt=0;
        for(int i=0; i<N; ++i) {
            cin >> w;
            reverse(w.begin(), w.end());
            for(int j=0; j<w.size(); ++j) {
                PIC p = make_pair(j, w[j]);
                M[p].push_back(w);
            }
        }
        for(auto W : M) {
            if(W.second.size() > 1) {
                PQ.emplace(W.second.size(), W.second);
            }
        }
        while(!PQ.empty()) {
            vector<string> W = PQ.top().second; PQ.pop();
            W.erase(remove_if(W.begin(),
                                W.end(),
                                [](string w){ return used.count(w); }),
                    W.end());
            if(W.size()) {
                used.insert(W.begin(), W.end());
                cnt += 2;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}

