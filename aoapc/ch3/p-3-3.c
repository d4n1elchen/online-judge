#include<stdio.h>
#include<string.h>

#define maxn 20

int m[maxn][maxn];

int main()
{
  int n, x, y, p = 1, d = 2;
  memset(m, 0, sizeof(m));
  scanf("%d", &n);
  x = 0;
  y = n-1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      m[x][y] = p++;
      if(d == 1) x--;
      else if(d == 2) x++;
      else if(d == 3) y--;
      else if(d == 4) y++;
    }
  }
}
