#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 10004;
int A[maxn];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, max=0, cnt=0;

    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> A[i];
        if(A[i] > max) max = A[i];
        if((i+1) == max) ++cnt;
    }
    cout << cnt;

    return 0;
}

