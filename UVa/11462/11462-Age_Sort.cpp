#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

const int max_len = 2000000+100;

vector<int> v;
int a[max_len];

int main()
{
  int n, x;
  char c;
  while(scanf("%d", &n) && n != 0) {
    v.clear();
    for(int i=0; i<n; i++) {
      scanf("%d", &x);
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++) {
      if(i==n-1) c='\n'; else c=' ';
      printf("%d%c", v[i], c);
    }
  }
}
