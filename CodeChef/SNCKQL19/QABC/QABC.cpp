#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

int main()
{
    int T, N;
    LL a, b;
    vector<LL> A, B, diff;
    bool tak;

    cin >> T;
    while(T--)
    {
        cin >> N;
        A.resize(N);
        B.resize(N);
        diff.resize(N);
        tak = true;
        for(int n=0; n<N; ++n)
        {
            cin >> A[n];
        }
        for(int n=0; n<N; ++n)
        {
            cin >> B[n];
            diff[n] = B[n] - A[n];
        }
        for(int n=0; n<N-2; ++n)
        {
            if(diff[n])
            {
                if(diff[n] < 0)
                {
                    tak = false;
                    break;
                }
                diff[n+2] -= 3*diff[n];
                diff[n+1] -= 2*diff[n];
                diff[n+0] -= 1*diff[n];
            }
        }
        if(diff[N-1] || diff[N-2]) tak = false;
        cout << (tak? "TAK\n": "NIE\n");
    }
}
