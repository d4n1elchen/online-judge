#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

priority_queue<PII, vector<PII>, greater<PII>> PQ;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N, T, s, d, at;
    cin >> N >> T;
    for(int i=0; i<N; ++i) {
        cin >> s >> d;
        if (T<s) at = s;
        else if(T==s) at = 0;
        else at = d-(T-s)%d;
        PQ.emplace(at, i+1);
    }
    cout << PQ.top().second << endl;

    return 0;
}

