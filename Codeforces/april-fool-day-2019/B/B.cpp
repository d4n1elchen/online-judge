#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int a;
    cin >> a;
    if(a==5 || a==46
        || a==2
        || a==3
        || a==4
        || a==12
        || a==30
        || a==35 // 17
        || a>50
        ) cout << "YES" << endl;
    else if(a==13 || a==24
            || a==1
            || a==6
            || a==7
            || a==8
            || a==9
            || a==10
            || a==11
            || a==14
            || a==16
            || a==20
            || a==27
            || a==28
            || a==37
            || a==38
            || a<99) cout << "NO" << endl;

    return 0;
}

