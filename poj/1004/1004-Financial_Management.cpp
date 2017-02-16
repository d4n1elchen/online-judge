#include<cstdio>

int main()
{
  double x, sum=0, avg=0;
  for(int i=0; i<12; i++) {
    scanf("%lf", &x);
    sum += x;
  }
  avg = sum/12;
  printf("$%.2f\n", avg);
  return 0;
}
