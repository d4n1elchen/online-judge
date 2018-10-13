#include<iostream>
using namespace std;

int main()
{
    int T;
    long long s, a, b, c;
    cin >> T;

    for(int t = 0; t < T; ++t)
    {
        cin >> s >> a >> b >> c;
        cout << (s/c)/a*b + s/c << endl;
    }
}
