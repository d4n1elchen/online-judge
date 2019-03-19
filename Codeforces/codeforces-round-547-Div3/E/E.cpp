#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 200005;
LL D[maxn];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    LL H, sum=0, sum_max=0, cnt, R;

    cin >> H >> N;

    for(int n=0; n<N; ++n) {
        cin >> D[n];
        sum += D[n];
        if(sum < sum_max) sum_max = sum;
        if((H+sum) <= 0) {
            cout << n+2;
            return 0;
        }
    }
    if(sum > 0) {
        cout << -1;
        return 0;
    }
    sum = -sum;

    cnt = N * ((H+sum_max) / sum);

    R = (H+sum_max) % sum;

    for(int n=0; n<N; ++n) {
        R += D[n];
        if(R <= 0) {
            cout << cnt;
            return 0;
        }
        ++cnt;
    }

    return 0;
}

