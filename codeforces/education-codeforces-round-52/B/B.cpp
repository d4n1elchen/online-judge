#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    long double n, m;
    long long mi, ma, ma_v, mi_v;
    cin >> n >> m;

    ma_v = (long long)ceill((1 + sqrt(1 + 8*m)) / 2);
    ma = (long long)n - (ma_v == 1 ? 0 : ma_v);
    mi_v = n - 2 * m;
    mi = mi_v < 0 ? 0 : mi_v;

    cout << mi << ' ' << ma << endl;
}
