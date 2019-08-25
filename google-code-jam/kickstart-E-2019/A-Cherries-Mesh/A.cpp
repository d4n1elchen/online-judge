#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxN = 100005;
int group[maxN];

void Init(int N) {
    for(int i=0; i<=N; ++i) group[i] = i;
}

int Find(int a) {
    if(group[a]==a) return a;
    else return group[a] = Find(group[a]);
}

bool Union(int a, int b) {
    int ma = Find(a);
    int mb = Find(b);
    if(ma != mb) {
        group[ma] = mb;
        return true;
    } else return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int T, N, M, c, d, ans, l;

    cin >> T;
    for(int t=1; t<=T; ++t) {
        cin >> N >> M;
        Init(N);
        ans = 0;
        for(int m=0; m<M; ++m) {
            cin >> c >> d;
            if(Union(c, d)) ans += 1;
        }
        l = Find(1);
        for(int i=2; i<=N; ++i) {
            if(Find(i) != l) {
                Union(i, l);
                ans += 2;
            }
        }
        cout << "Case #" << t << ": " << ans <<endl;
    }


    return 0;
}

