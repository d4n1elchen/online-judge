#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

int diag_cnt(int N, int M, int x, int y) {
    int TL, BL, TR, BR;
    TL = min(x-1, y-1); TR = min(N-x, y-1);
    BL = min(x-1, M-y); BR = min(N-x, M-y);
    return TL+BL+TR+BR;
}

bool see_king(int X, int Y, int x, int y) {
    return (x == X) || (y == Y) || (abs(X-x) == abs(Y-y));
}

int main()
{
    int T, N, M, X, Y, TL, BL, TR, BR;
    scanf("%d", &T);
    while(T--)
    {
        LL ans = 0;
        scanf("%d %d %d %d", &N, &M, &X, &Y);
        TL = min(X-1, Y-1); TR = min(N-X, Y-1);
        BL = min(X-1, M-Y); BR = min(N-X, M-Y);
        for(int x=1; x<=N; x++)
            for(int y=1; y<=M; y++) {
                if(x==X && y==Y) continue;
                if(see_king(X, Y, x, y)) {
                    ans += (N-1)*(M-1) - diag_cnt(N, M, x, y);
                    if(abs(X-x) == abs(Y-y))
                        ans += (x>X && y>Y)? TL:
                            (x>X && y<Y)? BL:
                            (x<X && y>Y)? TR: BR; // (x<X && y<Y)
                    else if(y==Y)
                        ans += (x>X)? (X-1): (N-X);
                    else if(x==X)
                        ans += (y>Y)? (Y-1): (M-Y);
                } else {
                    ans += (N-1)*(M-1) - 1 - diag_cnt(N, M, x, y);
                }
            }
        printf("%lld\n", ans);
    }
}
