#include<cstdio>

int a[1010];

int main()
{
  int n, meo, tmp;
  while(~scanf("%d", &n)) {
    meo = 0;
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n-1; i++) {
      for(int j=0; j<n-1-i ; j++) {
        if(a[j]>a[j+1]) {
          tmp = a[j];
          a[j] = a[j+1];
          a[j+1] = tmp;
          meo++;
        }
      }
    }
    printf("Minimum exchange operations : %d\n", meo);
  }
}
