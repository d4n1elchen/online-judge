#include<cstdio>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;

priority_queue<int> prio;
queue< pair<int,int> > q;

int main()
{
  int c;
  int n, m, x;
  int cnt;
  pair<int,int> temp;
  scanf("%d", &c);
  while(c--) {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
      scanf("%d", &x);
      q.push(make_pair(i, x));
      prio.push(x);
    }
    cnt = 0;
    while(!q.empty()) {
      if(q.front().second != prio.top()) {
        temp = q.front();
        q.pop();
        q.push(temp);
      } else {
        cnt++;
        if(q.front().first == m) printf("%d\n", cnt);
        q.pop();
        prio.pop();
      }
    }
  }
}
