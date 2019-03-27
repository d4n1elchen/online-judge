#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

priority_queue<int, vector<int>, greater<int>> PQ;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N,M,a,ma=0,mi;
    cin >> N >> M;
    for(int i=0; i<N; ++i) {
        cin >> a;
        PQ.push(a);
        ma = max(ma, a);
    }
    for(int i=0; i<M; ++i) {
        a = PQ.top() + 1; PQ.pop();
        PQ.push(a);
    }
    while(!PQ.empty()) {
        if(PQ.size()==1) mi=PQ.top();
        PQ.pop();
    }
    cout << mi << " " << ma+M << endl;

    return 0;
}

