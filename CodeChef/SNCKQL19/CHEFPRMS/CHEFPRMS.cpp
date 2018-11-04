#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

int main()
{
    int T, N;
    vector<bool> prime(100, true);
    vector<int> semip;
    vector<bool> valid(200, false);

    prime[0] = prime[1] = false;
    for(int i=2; i<10; ++i)
    {
        if(prime[i])
        {
            for(int j=i*i; j<100; j+=i)
            {
                prime[j] = false;
            }
        }
    }

    for(int i=0; i<100; ++i)
    {
        if(prime[i])
        {
            for(int j=i+1; j<100 && i*j<200; ++j)
            {
                if(prime[j]) semip.push_back(i * j);
            }
        }
    }

    for(int i=0; i<semip.size(); ++i)
    {
        for(int j=0; j<semip.size(); ++j)
        {
            if(semip[i] + semip[j] <= 200 && !valid[semip[i] + semip[j]])
                valid[semip[i] + semip[j]] = true;
        }
    }

    cin >> T;
    while(T--)
    {
        cin >> N;
        cout << (valid[N] ? "YES" : "NO") << endl;
    }
}
