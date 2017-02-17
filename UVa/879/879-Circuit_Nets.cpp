#include<bits/stdc++.h>
using namespace std;
const int len = 1000000;
int pins[len+100]={0};
int _count[len+100]={0};

void Init(int n)
{
  for(int i=1; i<=n; i++) pins[i] = i;
}

void Clear(int n)
{
  for(int i=1; i<=n; i++) {
    pins[i] = 0;
    _count[i] = 0;
  }
}

int Find(int x)
{
  if(x==pins[x]) return x;
  else return pins[x] = Find(pins[x]);
}

void Union(int x, int y)
{
  int X = Find(x);
  int Y = Find(y);
  pins[Y] = X;
}

void printArr(int n)
{
  for(int i=1; i<=n; i++) printf("%d ", pins[i]);
  putchar('\n');
}

int main()
{
  int N, n;
  int c = 0;
  string str;
  scanf("%d", &N);
  while(N--) {
    int pin1, pin2;
    cin >> n;
    getline(cin, str);
    Init(n);
    /* cout << "n = " << n << endl; */
    /* printArr(n); */
    c = 0;
    while(getline(cin, str) && str.compare("")) {
      stringstream ss(str);
      while(ss >> pin1 >> pin2)
        Union(pin1, pin2);
    }
    /* printArr(n); */
    for(int j=1; j<=n; j++) {
      _count[Find(j)]++;
      if(_count[Find(j)] == 1) c++;
    }
    printf("%d\n", c);
    if(N>0) printf("\n");
    Clear(n);
  }
}

