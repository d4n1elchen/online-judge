#include<cstdio>

int main()
{
  int a, b, t, max;
  while(~scanf("%d %d", &a, &b)) {
    printf("%d %d ", a, b);
    max = 1;
    if(a>b) { t=b; b=a; a=t; }
    for(int i=a; i<=b; i++) {
      int n = i;
      int tmax = 1;
      while(n!=1) {
        if(n%2!=0) n = 3*n+1;
        else n = n/2;
        tmax++;
      }
      max = tmax>max? tmax: max;
    }
    printf("%d\n", max);
  }
  return 0;
}
