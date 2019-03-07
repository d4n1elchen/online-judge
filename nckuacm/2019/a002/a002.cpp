#include<bits/stdc++.h>
using namespace std;

int cnt[2001];

int main()
{
    int N, a, mi=1000000;
    bool first=true;
    memset(cnt, 0, sizeof(cnt));
    cin >> N;
    while(N--) {
        cin >> a;
        cnt[a]++;
        if(a < mi) mi = a;
    }
    for(int i=mi; i<2001; ++i) {
        if(!cnt[i]) continue;
        for(int j=0; j<cnt[i]; ++j)
            if(first) {
                cout << i;
                first = false;
            }
            else {
                cout << " " << i;
            }
    }
}
