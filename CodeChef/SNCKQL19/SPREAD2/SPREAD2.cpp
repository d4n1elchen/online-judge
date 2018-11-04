#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

int main()
{
    int T;
    LL N, sum, sprd, cnt, A, n;
    bool finished;

    cin >> T;
    while(T--)
    {
        cin >> N;

        cin >> A;
        n = 1;

        sum = A;
        cnt = 0;

        finished = false;
        while(!finished)
        {
            sprd = sum;
            for(LL s=0; s<sprd; ++s)
            {
                cin >> A;
                n++;
                sum += A;
                if(n == N)
                {
                    finished = true;
                    break;
                }
            }
            cnt++;
        }
        cout << cnt << endl;
    }
}
