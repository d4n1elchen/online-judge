#include<bits/stdc++.h>
using namespace std;
map<int, int> m;
int arr[1000000+100];
int main()
{
  int x, n=0;
  while(~scanf("%d", &x)) {
    if(m.find(x) == m.end()) {
      m[x] = 1;
      arr[n++] = x;
    } else m[x]++;
  }
  for(int i=0; i<n; i++)
    printf("%d %d\n", m.find(arr[i])->first, m.find(arr[i])->second);
  return 0;
}
