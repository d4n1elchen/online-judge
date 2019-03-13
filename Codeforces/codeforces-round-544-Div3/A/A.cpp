#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int h1, h2, m1, m2, mm1, mm2, mmd;
    string s;

    cin >> s;
    h1 = stoi(s.substr(0, 2));
    m1 = stoi(s.substr(3, 5));
    mm1 = h1 * 60 + m1;
    cin >> s;
    h2 = stoi(s.substr(0, 2));
    m2 = stoi(s.substr(3, 5));
    mm2 = h2 * 60 + m2;

    mmd = (mm1 + mm2) / 2;

    printf("%02d:%02d", mmd/60, mmd%60);

    return 0;
}

