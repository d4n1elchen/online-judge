#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int A[32];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> A[i];
    }
    int cnt=0, i; bool ok=false;
    for(i=N; i>1; i>>=1) {
        for(int j=0; j<N; ++j) {
            if(!cnt) {
                ++cnt;
                if(A[j]<=A[j+1]) ok=true;
            }
            else if(ok && A[j]>=A[j-1]) {
                ++cnt;
                if(cnt==i) { break; }
                ok=true;
            }
            else {
                ++cnt;
                ok=false;
            }
            if(cnt==i) cnt=0;
        }
        if(ok) break;
    }
    cout << i << endl;

    return 0;
}
