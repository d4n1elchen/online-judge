#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, cnt[15] = { 0, 0, 0, 0, 0, 0, 2, 0, 16, 0, 94, 0, 496, 0, 2498 };
    cin >> N;
    cout << cnt[N-1];

    return 0;
}

