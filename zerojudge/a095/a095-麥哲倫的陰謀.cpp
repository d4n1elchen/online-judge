#include<cstdio>
int main()
{
  int n, m;
  while(~scanf("%d %d", &n, &m)) {
    if(n != m)
      printf("%d\n", m+1);
    else
      printf("%d\n", m);
  }
}
