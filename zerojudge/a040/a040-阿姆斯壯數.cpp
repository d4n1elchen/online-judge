#include<cstdio>
#include<cmath>

int main()
{
  int n, m;
  bool first, find;
  while(~scanf("%d %d", &n, &m)) {
    first = true;
    find = false;
    for(int i=n; i<=m; i++) {
      int k = i;
      int l = floor(log10(k)) + 1;
      int sum = 0;
      while(k) {
        sum += pow(k%10, l);
        k /= 10;
      }
      if(i == sum) {
        if(!first) putchar(' ');
        first = false;
        printf("%d", i);
        find = true;
      }
    }
    if(!find) printf("none");
    putchar('\n');
  }
}

