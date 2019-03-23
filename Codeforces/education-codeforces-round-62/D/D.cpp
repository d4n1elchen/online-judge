#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    LL N, sum=0;

    cin >> N;

    for(LL i=2; i<=N-1; ++i) {
        sum += i*(i+1);
    }

    cout << sum;

    return 0;
}

