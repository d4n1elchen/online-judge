#include<bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef vector<LL> VL;
typedef vector<int> VI;

int T, N;

vector<tuple<int, int, int>> act;
char sche[10000];

void solve()
{
    cin >> N;
    act.resize(N);
    for(int i=0; i<N; ++i) {
        cin >> get<0>(act[i]) >> get<1>(act[i]);
        get<2>(act[i]) = i;
    }
    sche[N] = 0;
    sort(act.begin(), act.end());
    int curr = 0;
    tuple<int, int, int> last = make_tuple(0, 0, 0);
    bool ok = true;
    for(int i=0; i<N; ++i) {
        sche[get<2>(act[i])] = curr? 'C': 'J';
        if(i+1 < N && get<0>(act[i+1]) < get<1>(act[i])) {
            if(get<0>(act[i+1]) < get<1>(last)) {
                ok = false;
            }
            curr = !curr;
            last = act[i];
        }
    }
    if(ok) {
        printf("%s", sche);
    }
    else {
        printf("IMPOSSIBLE");
    }
    puts("");
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> T;

    int i=1;
    while(T--) {
        printf("Case #%d: ", i++);
        solve();
    }

    return 0;
}

