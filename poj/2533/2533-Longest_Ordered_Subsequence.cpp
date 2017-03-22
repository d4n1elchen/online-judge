#include<cstdio>
#include<algorithm>
#define MAX 1020

using namespace std;

int arr[MAX];
int LIS[MAX];

int main()
{
  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    LIS[i] = 1;
    scanf("%d", &arr[i]);
  }

  int m = 1;

  for(int i=1; i<N; i++)
    for(int j=i-1; j>=0; j--)
      if(arr[j]<arr[i]) {
        LIS[i] = max(LIS[i], LIS[j]+1);
        if(LIS[i] > m) m = LIS[i];
      }

  printf("%d", m);
  /* for(int i=0; i<N; i++) printf("%d ", arr[i]); */
  /* putchar('\n'); */
  /* for(int i=0; i<N; i++) printf("%d ", LIS[i]); */
  /* putchar('\n'); */

}
