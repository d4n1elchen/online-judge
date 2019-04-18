#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL MM = 1000000000 + 7;

LL MSB(LL n)
{
    if (n == 0)
        return 0;

    LL msb = 0;
    while (n != 0) {
        n = n / 2;
        msb++;
    }

    return msb;
}

LL sum(LL a1, LL n)
{
    return (a1*n%MM + n*n%MM - n)%MM;
}

LL cnt(LL a1, LL n)
{
    return 2*(a1*n + n*n - n);
}

LL finda(LL n)
{
    LL a1 = 1 + !(n&1);
    return (a1 + 2 * (cnt(a1, n/2)-1)%MM + 1)%MM;
}

LL findn(LL n1, LL n2)
{
    LL a1 = 1 + !(n2&1), n;
    n = (a1 + 2 * (cnt(a1, n2/2)-1)%MM + 1)%MM;
    a1 = 1 + !(n1&1);
    n -= (a1 + 2 * (cnt(a1, n2/2)-1)%MM + 1)%MM;
    return n;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    LL l, r, lb, rb, s, even_n=0, odd_n=0, even_a1, odd_a1;
    cin >> l >> r;

    lb = MSB(l);
    rb = MSB(r);

    lr = (1<<lb) - l;
    rr = r - (1<<(rb-1)) -1;

    if(lb&1) {
        even_n += lr;
        even_a1 = (finda(lb) + 2*even_n%MM)%MM;
        odd_a1 = finda(lb+1);
    }
    else {
        odd_n += lr;
        odd_a1 = (finda(lb) + 2*odd_n%MM)%MM;
        even_a1 = find(lb+1);
    }

    if(rb&1) even_n += rr;
    else odd_n + rr;

    return 0;
}

