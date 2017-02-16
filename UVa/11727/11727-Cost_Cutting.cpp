#include<cstdio>

int main()
{
  int n, a[3], result=0;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    for(int j=0; j<3; j++) {
      scanf("%d", &a[j]);
    }
    if(a[0] > a[1] && a[0] > a[2]) printf("Case %d: %d\n", i+1, a[1]>a[2]? a[1]: a[2]);
    else if(a[1] > a[2] && a[1] > a[0]) printf("Case %d: %d\n", i+1, a[2]>a[0]? a[2]: a[0]);
    else if(a[2] > a[0] && a[2] > a[1]) printf("Case %d: %d\n", i+1, a[0]>a[1]? a[0]: a[1]);
  }
  return 0;
}

