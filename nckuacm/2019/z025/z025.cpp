#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 100005;
int DS[maxn];
int C[maxn];

void Init(int N) {
    for(int i=1; i<=N; ++i) {
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
    int N,M,Q,a,b;
    cin >> N >> M >> Q;
    Init(N);
    for(int i=0; i<M; ++i) {
        cin >> a >> b;
        Union(a, b);
    }
    for(int i=0; i<Q; ++i) {
        cin >> a >> b;
        if(Find(a)==Find(b)) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}

