#include<stdio.h>
#include<string.h>
#define maxn 1010

int light[maxn];

int main()
{
  int n, k, first = 1;
  memset(light, 0, sizeof(light));
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= k; i++) {
    for(int j = i; j <= n; j+= i) {
      light[j] = !light[j];
    }
  }
  for(int i = 1; i <= n; i++) {
    if(light[i]) {
      if (first)
        first = 0;
      else
        putchar(' ');
      printf("%d", i);
    }
  }
  putchar('\n');
  return 0;
}
