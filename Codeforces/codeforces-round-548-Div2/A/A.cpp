#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, s, sum=0;
    char c;

    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> c;
        s = c - '0';
        if(s%2 == 0) sum += i+1;
    }
    cout << sum;

    return 0;
}
