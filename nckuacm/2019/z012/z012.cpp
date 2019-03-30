#include<bits/stdc++.h>
#define FF(t) get<0>(t)
#define SS(t) get<1>(t)
#define TT(t) get<2>(t)
using namespace std;
typedef long long LL;
typedef tuple<int, int, int> TIII;

int const maxn = 100005;
int DS[maxn];
int CNT[maxn];
int DEG[maxn];
vector<TIII> edges;

void Init(int N) {
    for(int i=1; i<=N; ++i) {
        DS[i] = i;
        DEG[i] = 0;
    }
}

int Find(int a) {
    if(DS[a]==a) return a;
    else return DS[a] = Find(DS[a]);
}

void Union(int a, int b) { DS[Find(a)] = Find(b); }

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, M, a, b, cnt;
    TIII e;
    cin >> N >> M;
    Init(N);
    for(int i=0; i<M; ++i) {
        cin >> a >> b;
        ++DEG[a]; ++DEG[b];
        edges.emplace_back(0, a, b);
    }
    for(int i=0; i<M; ++i) {
        e = edges[i];
        FF(edges[i]) = min(DEG[SS(e)], DEG[TT(e)]);
    }
    sort(edges.begin(), edges.end());
    cnt = N-1;

    for(int i=N-1; i>=0; --i) {
        while(!edges.empty() && FF(edges.back()) > i) {
            e = edges.back(); edges.pop_back();
            a = Find(SS(e));
            b = Find(TT(e));
            if(a!=b) { --cnt; Union(a, b); }
        }
        CNT[i] = cnt;
    }
    cout << CNT[0];
    for(int i=1; i<N; ++i) {
        cout << " " << CNT[i];
    }

    return 0;
}

