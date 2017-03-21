#include<cstdio>
#include<cmath>
#include<cstring>
const long long int MAX = 1000010;
bool isPrime[MAX];

void Erato(long long int mn, long long int n)
{
  for(long long int i=mn; i<=sqrt(n); ++i) {
    if(isPrime[i]) {
      for(long long int j=i*i; j<n; j +=i) isPrime[j] = false;
    }
  }
}

int main()
{
  memset(isPrime, 1, sizeof(isPrime));
  isPrime[0]=isPrime[1]=false;

  long long int n, mn = 2, tn;
  while(~scanf("%lld", &n) && n>0) {
    if(mn != 1000000) {
      if(n > 1000000) {
        Erato(mn, 1000000);
        mn = 1000000;
      } else if(n > mn) {
        Erato(mn, n);
        mn = n;
      }
    }
    /* for(long long int i=0; i<=n; i++) { */
    /*   if(isPrime[i]) printf("%lld ", i); */
    /* } */
    /* putchar('\n'); */
    tn = n;
    if(n > 1000000) n = 1000000;
    for(long long int i=0; i<=n; i++) {
      if(isPrime[i])
        while(tn%i == 0) {
          printf("    %lld\n", i);
          tn /= i;
        }
    }
    if(tn>1) printf("    %lld\n", tn);
    putchar('\n');
  }
}
