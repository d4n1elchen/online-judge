#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const minn = 100005;
int DS[minn];
int C[minn];
int MIN[minn];

void Init(int N) {
    for(int i=0; i<N; ++i) {
        MIN[i] = INF;
        DS[i] = i;
    }
}

int Find(int a) {
    if(DS[a]==a) return a;
    else return DS[a] = Find(DS[a]);
}

void Union(int a, int b) {
    DS[Find(a)] = Find(b);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, M, u, v, g;
    LL cnt=0;
    cin >> N >> M;
    Init(N);
    for(int i=0; i<N; ++i) {
        cin >> C[i];
    }
    for(int i=0; i<M; ++i) {
        cin >> u >> v;
        Union(u-1, v-1);
    }
    for(int i=0; i<N; ++i) {
        g = Find(i);
        MIN[g] = min(MIN[g], C[i]);
        cout << g << ' ';
    }
    cout << endl;
    for(int i=0; i<N; ++i) {
        if(MIN[i]) cnt += MIN[i];
    }
    cout << cnt;

    return 0;
}

