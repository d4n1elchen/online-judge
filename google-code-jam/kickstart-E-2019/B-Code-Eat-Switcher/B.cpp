#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    LL T, D, S, C, E, A, B, c_sum, e_sum, p_sum, n_sum;
    cin >> T;
    for(LL t=1; t<=T; ++t) {
        cout << "Case #" << t << ": ";
        cin >> D >> S;
        c_sum = e_sum = p_sum = n_sum = 0;
        for(LL s=0; s<S; ++s) {
            cin >> C >> E;
            c_sum += C;
            e_sum += E;
            if(E-C > 0) p_sum += E-C;
            else n_sum += E-C;
        }
        for(LL d=0; d<D; ++d) {
            cin >> A >> B;
            if(A > c_sum || B > e_sum
                    || (B+A-c_sum) > p_sum
                    ) {
                cout << "N";
                continue;
            }
            cout << "Y";
        }
        cout << endl;
    }

    return 0;
}

