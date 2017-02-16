#include<iostream>
#include<string>
using namespace std;

int reduce(int i)
{
  int n=0;
  while(i) {
    n += i%10;
    i /= 10;
  }
  n += i;
  if(n>9) reduce(n);
  else return n;
}

int sum(string s)
{
  string::iterator it;
  int a=0;
  for(it = s.begin(); it < s.end(); ++it) {
    char c = *it;
    if( c >= 'a' && c <= 'z') a += (int)(c - 'a') + 1;
    else if( c >= 'A' && c <= 'Z') a += (int)(c - 'A') + 1;
    else continue;
  }
  if(a>9) return reduce(a);
  else return a;
}

int main()
{
  string n1, n2;
  int a1, a2;
  while(true) {
    if(!getline(cin, n1)) return 0;
    if(!getline(cin, n2)) return 0;
    a1 = sum(n1);
    a2 = sum(n2);
    if(a1 > a2) {
      if(a1==0) printf("\n");
      else printf("%.2f %%\n", (float)a2/a1*100);
    } else {
      if(a2==0) printf("\n");
      else printf("%.2f %%\n", (float)a1/a2*100);
    }
  }
  return 0;
}
