#include<bits/stdc++.h>
using namespace std;
const int len = 5000;
map<string, int> indices;
int creature[len+10]={0};
int _count[len+10]={0};

void Init(int n)
{
  for(int i=0; i<n; i++) creature[i] = i;
}

void Clear(int n)
{
  for(int i=0; i<n; i++) {
    creature[i] = 0;
    _count[i] = 0;
  }
}

int Find(int x)
{
  if(x==creature[x]) return x;
  else return creature[x] = Find(creature[x]);
}

void Union(int x, int y)
{
  int X = Find(x);
  int Y = Find(y);
  creature[Y] = X;
}

void printArr(int n)
{
  for(int i=0; i<n; i++) printf("%d ", creature[i]);
  putchar('\n');
  for(int i=0; i<n; i++) printf("%d ", _count[i]);
  putchar('\n');
}

int main()
{
  int c, r;
  int max = 0;
  string str, s1, s2;
  while(scanf("%d %d", &c, &r) && !(c==0 && r==0)) {
    Init(c);
    max = 0;
    for(int i=0; i<c; i++) {
      cin >> str;
      indices[str] = i;
    }
    for(int i=0; i<r; i++) {
      cin >> s1 >> s2;
      Union(indices[s1], indices[s2]);
    }
    for(int i=0; i<c; i++) {
      _count[Find(i)]++;
      if(_count[Find(i)] > max) max = _count[Find(i)];
    }
    printf("%d\n", max);
    Clear(c);
  }
}
