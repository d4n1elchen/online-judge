#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 200005;
LL A[maxn], INC[maxn], DEC[maxn];
int N, IN, DN;

void printA() { for(int i=0; i<N; ++i) cout << A[i] << ' '; cout << endl; }

void solve() {
    int i;
    IN=0;
    INC[IN++] = A[0];
    A[0] = -1;
    for(i=1; i<N; ++i) {
        if(A[i] > INC[IN-1]) {
            INC[IN++] = A[i];
            A[i] = -1;
        }
    }
    for(i=N-1; i>0 && A[i]==-1; --i);
    DN=0;
    if(A[i] != -1) {
        DEC[DN++] = A[i];
        A[i] = -1;
    }
    for(i=i-1; i>=0; --i) {
        if(A[i] < DEC[DN-1] && A[i] != -1) {
            DEC[DN++] = A[i];
            A[i] = -1;
        }
    }
    if(N != (IN+DN)) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << IN << endl;
        for(i=0; i<IN; ++i) {
            if(!i) cout << INC[i];
            else cout << " " << INC[i];
        }
        cout << endl;
        cout << DN << endl;
        for(i=0; i<DN; ++i) {
            if(!i) cout << DEC[i];
            else cout << " " << DEC[i];
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N;
    for(int i=0; i<N; ++i) cin >> A[i];
    sort(A, A+N);
    solve();

    return 0;
}

