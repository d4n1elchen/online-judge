// 應啦幹
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<LL, LL>> A;

int main()
{
    LL N, a, cnt=0;
    cin >> N;
    A.resize(2*N);
    for(LL i=0; i<2*N; ++i) {
        cin >> a;
        A[i] = make_pair(a, i);
    }
    sort(A.begin(), A.end());
    cnt += A[0].second + A[1].second;
    for(LL i=2; i<2*N; i+=2) {
        cnt += abs(A[i].second - A[i-2].second) + abs(A[i+1].second - A[i-1].second);
    }
    cout << cnt;
}
