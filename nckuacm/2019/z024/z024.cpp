#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

double EPS = 1e-16;

int main()
{
    int T;
    long double k, Z, L, R, N, M, E;
    scanf("%d", &T);

    while(T--) {
        scanf("%LF", &k);
        Z = 2*0.499*k;
        L=0; R=50;
        while((R-L)>EPS) {
            M=(L+R)/2;
            E=exp(-M);
            N=sin(E)/E-E*sin(E);
            if(N<Z) L=M;
            else R=M;
        }
        printf("%.9LF\n", R-5e-10);
    }

    return 0;
}

