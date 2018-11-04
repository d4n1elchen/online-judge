#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

const int maxn = 200000 + 10;
LL A[maxn];
set<LL> s;
vector<LL> vec;

int main()
{
    int T, N;
    LL a, maxa, cnt;
    scanf("%d", &T);
    for(int t=0; t<T; t++) {
        cnt = 0;
        maxa = 0;
        memset(A, 0, sizeof(A));
        s.clear();
        vec.clear();
        scanf("%d", &N);
        for(int n=0; n<N; n++) {
            scanf("%lld", &a);
            A[a]++;
            s.insert(a);
            if(maxa < a) maxa = a;
        }
        vec.assign(s.begin(), s.end());
        /* for(auto it=vec.begin(); it<vec.end(); ++it) cout << *it << ' '; */
        /* puts(""); */

        // 0
        if(A[0] >= 2) {
            if(A[0] >= 3) cnt += A[0]*(A[0]-1)*(A[0]-2)/6;
            for(int m=0; m<vec.size(); m++) if(vec[m] != 0) {
                cnt += A[vec[m]]*A[0]*(A[0]-1)/2;
            }
        }
        // 1
        if(A[1] >= 1) {
            if(A[1] >= 3) cnt += A[1]*(A[1]-1)*(A[1]-2)/6;
            for(int m=0; m<vec.size(); m++) if(vec[m] != 0 && vec[m] != 1) {
                if(A[vec[m]] >= 2) cnt += A[1]*A[vec[m]]*(A[vec[m]]-1)/2;
            }
        }
        // others
        for(int n=0; n<vec.size(); n++) {
            if(vec[n]==0 || vec[n] == 1) continue;
            else {
                if(A[vec[n]] >= 2) {
                    LL k = vec[n]*vec[n];
                    if(k < maxn && A[k]) {
                       cnt += A[vec[n]]*(A[vec[n]]-1)*A[k]/2;
                    }
                }
                for(int m=n+1; m<vec.size(); m++) {
                    LL k = vec[n]*vec[m];
                    if(k < maxn && A[k]) {
                       cnt += A[vec[n]]*A[vec[m]]*A[k];
                    }
                }
            }
        }
        printf("Case #%d: %lld\n", t+1, cnt);
    }
}
