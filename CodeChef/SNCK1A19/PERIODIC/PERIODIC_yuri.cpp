#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int N, a[maxn];

int main()
{
  int T;
  scanf("%d", &T);

  while(T--) {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
      scanf("%d", &a[i]);
    }

    for(int i = N-2; i >= 0; i--)
      if(a[i] == -1 && a[i+1] != -1 && a[i+1] != 1) a[i] = a[i+1]-1;

    int omaxi = -2, omidx; //original
    bool cover = false;
    for(int i = 0; i < N; i++) {
      if(omaxi < a[i]) {
        omaxi = a[i];
        omidx = i;
      }
    }
    if(omidx < N-1 && a[omidx+1] == 1) cover = true;

    /*
    for(int i = 0; i < N; i++) printf("%d ", a[i]);
    putchar('\n');
    */

    for(int i = 1; i < N; i++) if(a[i] == -1 && a[i-1] != -1) {
      if(cover) {
        if(a[i-1] != omaxi) a[i] = a[i-1]+1;
        else a[i] = 1;
      } else a[i] = a[i-1]+1;
    }

    /*
    for(int i = 0; i < N; i++) printf("%d ", a[i]);
    putchar('\n');
    */

    int maxi = -2, midx;
    for(int i = 0; i < N; i++)
      if(maxi < a[i]) { maxi = a[i]; midx = i; }

    bool inf = false, imp = false;
    if(midx == N-1 || a[midx+1] == -1) inf = true;

    for(int i = 1; i < N; i++)
      if(a[i-1] != -1 && a[i] != -1 && (
            (a[i] == 1 && a[i-1] != maxi) ||
            (a[i] != 1 && a[i]-a[i-1] != 1))) {
        imp = true;
        break;
      }

    if(imp) puts("impossible");
    else if(inf) puts("inf");
    else printf("%d\n", maxi);
  }

  return 0;
}
