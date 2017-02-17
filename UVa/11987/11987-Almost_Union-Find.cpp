#include<bits/stdc++.h>
using namespace std;
const int len = 100000;
int root[len+100]={0};
vector<int> sets[len+100];
int n;

void Init(int n)
{
  for(int i=1; i<=n; i++) {
    root[i] = i;
    sets[i].clear();
    sets[i].push_back(i);
  }
}

void Union(int x, int y)
{
  int X = root[x];
  int Y = root[y];
  if(X==Y) return;
  if(sets[X].size() >= sets[Y].size()) {
    for(int &n : sets[Y]) {
      sets[X].push_back(n);
      root[n] = X;
    }
    sets[Y].clear();
  } else {
    for(int &n : sets[X]) {
      sets[Y].push_back(n);
      root[n] = Y;
    }
    sets[X].clear();
  }
}

void Move(int x, int y)
{
  if(root[x] == root[y]) return;

  auto it = sets[root[x]].begin();
  while(*it!=x) it++;
  sets[root[x]].erase(it);

  sets[root[y]].push_back(x);
  root[x] = root[y];
}

int main()
{
  int m, cmd, p, q;
  while(~scanf("%d %d", &n, &m)) {
    Init(n);
    while(m--) {
      scanf("%d", &cmd);

      if(cmd == 1) {
        scanf("%d %d", &p, &q);
        Union(p, q);
      } else if (cmd == 2) {
        scanf("%d %d", &p, &q);
        Move(p, q);
      } else if (cmd == 3) {
        scanf("%d", &p);
        int sum = 0;
        for(int &n : sets[root[p]])
          sum+=n;
        printf("%d %d\n", sets[root[p]].size(), sum);
      }
    }
  }
}

