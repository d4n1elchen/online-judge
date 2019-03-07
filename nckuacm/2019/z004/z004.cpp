#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v, sv;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k, cnt;
    LL a, sum, psum;
    char s, ps;

    cin >> n >> k;
    v.resize(n);
    for(int i=0; i<n; ++i) {
        cin >> a;
        v[i] = a;
    }

    ps = 0;
    sum = 0;
    psum = 0;
    cnt = 0;

    for(int i=0; i<n; ++i) {
        cin >> s;
        if(s == ps) {
            psum += v[i];
        }
        else {
            if(cnt <= k) sum += psum;
            else {
                sort(sv.begin(), sv.end(), greater<>());
                for(int j=0; j<k; ++j) sum += sv[j];
            }
            sv.clear();
            cnt = 0;
            psum = v[i];
        }
        sv.push_back(v[i]);
        cnt++;
        ps = s;
    }
    if(cnt <= k) sum += psum;
    else {
        sort(sv.begin(), sv.end(), greater<>());
        for(int j=0; j<k; ++j) sum += sv[j];
    }
    cout << sum << endl;
}
