#include<cstdio>
#include<cmath>
double p, q, r, s, t, u;

double f(double x)
{
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
  while(~scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u)) {
    double left = 0.0, right = 1.0;
    if(f(left)*f(right)>0) {
      printf("No solution\n");
      continue;
    }
    while(right-left > 0.000000001) {
      double mid = (left+right) / 2.0;
      if(f(mid)*f(right)<=0) left = mid;
      else right = mid;
    }
    printf("%.4lf\n", (left+right) / 2.0);
  }
}
