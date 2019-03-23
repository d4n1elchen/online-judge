#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

priority_queue<LL, vector<LL>, greater<LL>> PQ;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    while((cin>>N) && N != 0) {
        LL k, k1, k2, sum = 0;
        for(int i=0; i<N; ++i) {
            cin >> k;
            PQ.push(k);
        }
        while(PQ.size() > 1) {
            k1 = PQ.top(); PQ.pop();
            k2 = PQ.top(); PQ.pop();
            PQ.push(k1 + k2);
            sum += k1 + k2;
        }
        PQ.pop();
        cout << sum << endl;;
    }

    return 0;
}

