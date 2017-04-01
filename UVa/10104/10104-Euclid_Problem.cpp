#include<cstdio>

int exGCD(int A, int B, int &X, int &Y)
{
  if(B == 0) {
    X = 1;
    Y = 0;
    return A;
  } else {
    int D = exGCD(B, A%B, X, Y);
    int t = X;
    X = Y;
    Y = t-(A/B)*Y;
    return D;
  }
}

int main()
{
  int A, B;
  while(~scanf("%d %d", &A, &B)) {
    int X, Y, D;
    D = exGCD(A, B, X, Y);
    printf("%d %d %d\n", X, Y, D);
  }
}
