#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    int T;
    double Z, A, B;
    scanf("%d",&T);
    while(T--) {
        scanf("%lf",&Z);
        if(Z==0) {
            A=0; B=0;
        } else if(Z<4) {
            printf("Null\n");
            continue;
        } else {
            A=(Z+sqrt(Z*(Z-4)))/2;
            B=Z-A;
        }
        printf("%.9lf %.9lf\n",A,B);
    }

    return 0;
}

