#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
typedef priority_queue<PLL, vector<PLL>, greater<PLL>> PQ;

int const maxn = 10004;
LL height[maxn];
int visit[maxn];
map<LL, PQ> G;
map<LL, vector<PLL>> Gv;
queue<LL> Q;

void clear() {
    G.clear();
    Gv.clear();
    while(!Q.empty()) Q.pop();
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int T;

    cin >> T;
    for(int t=1; t<=T; ++t) {
        clear();
        LL N, M, S, mi=9999999, u, v, curr, sumc=0, sumw=0;
        PLL p;
        bool failc, failw;
        cin >> N >> M >> S;
        for(LL i=0; i<N; ++i) {
            cin >> height[i];
            mi = min(mi, height[i]);
        }
        for(LL i=0; i<M; ++i) {
            cin >> u >> v;
            G[u].push(make_pair(height[v]-height[u], v));
            G[v].push(make_pair(height[u]-height[v], u));
            Gv[u].push_back(make_pair(height[v]-height[u], v));
            Gv[v].push_back(make_pair(height[u]-height[v], u));
        }

        // Solve car
        curr = S;
        while(height[curr] != mi) {
            if(G[curr].empty() || G[curr].top().first >= 0) break;
            ++sumc;
            curr = G[curr].top().second;
        }
        failc = (height[curr] != mi);

        // Solve walk
        for(int i=0; i<N; ++i) { visit[i] = -1; }
        Q.push(S);
        visit[S] = 0;
        while(!Q.empty()) {
            curr = Q.front(); Q.pop();
            if(height[curr] == mi) {
                sumw = visit[curr];
                break;
            }
            for(size_t i=0; i<Gv[curr].size(); ++i) {
                p = Gv[curr][i];
                if(visit[p.second]<0) {
                    Q.push(p.second);
                    visit[p.second] = visit[curr] + 1;
                }
            }
        }
        failw = (height[curr] != mi);

        cout << "Case #" << t << ": ";
        if(failc && failw) {
            cout << "Call 119!" << endl;
        } else if(failc) {
            cout << sumw*6 << endl;
        } else {
            cout << abs(sumc - sumw*6) << endl;
        }
    }

    return 0;
}

