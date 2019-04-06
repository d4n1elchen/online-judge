#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int const maxn = 100 + 5;
int A[maxn], B[maxn];
char digits[maxn];

void print_ans(int N) {
    int start;

    start = false;
    for(int i=0; i<N; ++i) {
        if(A[i]==0 && !start) continue;
        start = true;
        cout << A[i];
    }
    cout << ' ';

    start = false;
    for(int i=0; i<N; ++i) {
        if(B[i]==0 && !start) continue;
        start = true;
        cout << B[i];
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;

    cin.get();
    for(int t=1; t<=T; t++) {
        int dn=0, x, a, b;
        while(cin.get(digits[dn]) && digits[dn]!='\n') {
            x = digits[dn] - '0';
            if(x==0) {
                a=0; b=0;
            } else if((x-1) == 4) {
                a=2; b=x-2;
            } else {
                a=1; b=x-1;
            }
            A[dn] = a;
            B[dn] = b;
            dn++;
        }
        cout << "Case #" << t << ": ";
        print_ans(dn);
    }

    return 0;
}

