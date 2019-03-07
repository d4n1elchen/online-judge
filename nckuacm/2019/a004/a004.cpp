#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
  	ios::sync_with_stdio(false);
    cin.tie(0);

    LL T, N, a;
    cin >> T;
    while(T--) {
        LL sum=0, ma=-66666666;
        cin >> N;
        while(N--) {
            cin >> a;
            sum += a;
            sum = max(sum, a);
            ma = max(sum, ma);
        }
        cout << ma << endl;
    }
}
