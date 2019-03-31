#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef priority_queue<LL, vector<LL>, greater<LL>> PQLL;

PQLL odd;
PQLL even;

LL solve() {
    PQLL first, second;
    LL sum=0;
    int dif;
    if(odd.size()==even.size()) return 0;
    if(odd.size()>even.size()) { first=odd; second=even; }
    else { first=even; second=odd; }
    dif = first.size()-second.size()-1;
    for(int i=0; i<dif; ++i) { sum += first.top(); first.pop(); }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    LL a;
    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> a;
        if(a&1) odd.push(a);
        else even.push(a);
    }
    cout << solve() << endl;

    return 0;
}

