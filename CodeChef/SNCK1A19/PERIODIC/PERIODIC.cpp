#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

int main()
{
    int T;
    LL N, A, mA, dif;
    bool ok;
    vector<LL> vec;

    cin >> T;
    while(T--) {
        cin >> N;
        vec.resize(N);
        ok = true;
        K = 0;
        for(int n = 0; n < N; ++n) {
            cin >> vec[n];
            if(ok && n > 0 && vec[n] != -1 && vec[n-1] != -1) {
                dif = vec[n] - vec[n-1];
                if(dif != 1) {
                    if(vec[n] != 1) ok = false;
                    else {
                        if(!mA) mA = A;
                        else if(A != mA) { ok = false; }
                        A = 0;
                    }
                }
            }
            if(vec[n] > A) A = vec[n];
        }
    }
}
