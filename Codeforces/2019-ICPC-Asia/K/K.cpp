#include<bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

int const MOD = 1e9 + 7;
int const MAXN = 1e5;

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef vector<LL> VL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int N, Q;
    bitset<MAXN> b;
    bitset<MAXN> mask;
    bitset<MAXN> z(0);

    cin >> N >> Q;
    vector<int> lr(N, 0);

    char c;
    for(int i=0; i<N; ++i) {
        cin >> c;
        b[i] = c-'A';
    }
    int tmp;
    int L,R,A,B;
    for(int i=0; i<Q; i++){
        cin >> tmp;
        if(tmp==1){
            cin>>L>>R;
            /* mask = (~z << (L-1)) & ~(~z << R); */
            /* b = (b & ~mask) | (~b & mask); */
            for(int i=0;)
        }
        else{
            cin>>L>>R>>A>>B;
            L--; R--;
            bool cur = b[L];
            int cnt = 1;
            for(int i=L+1; i<=R; i++){
                if(b[i] == cur) {
                    cnt++; continue;
                }
                else {
                    if(cur) B = ((cnt * A) % MOD + B) % MOD;
                    else A = (A + (B * cnt) % MOD) % MOD;
                    cur = b[i];
                    cnt = 1;
                }
            }
            if(cur) B = ((cnt * A) % MOD + B) % MOD;
            else A = (A + (B * cnt) % MOD) % MOD;
            cout<<A<<" "<<B<<endl;
        }
        /* for(int i=0; i<N; ++i) { */
        /*     cout << b[i]; */
        /* } cout << endl; */
    }
    return 0;

}
