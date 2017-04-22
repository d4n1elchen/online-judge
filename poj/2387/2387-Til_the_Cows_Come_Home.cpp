#include<cstdio>
#include<vector>
#include<cstdlib>
#define INF 999999999
#define MAX 1080
using namespace std;

struct tupStruct {
  int u, v, w;
};
typedef struct tupStruct Tuple;

int dis[MAX];
vector<Tuple*> edges;

void relax(int u, int v, int w)
{
  if(dis[u]+w < dis[v]) dis[v] = dis[u]+w;
  if(dis[v]+w < dis[u]) dis[u] = dis[v]+w;
}

void BellmanFord(int n, int source)
{
  dis[source] = 0;
  for(int i=1; i<=n; i++)
    if(i!=source)
      dis[i] = INF;

  int u, v, w;
  for(int i=0; i<n-1; i++)
    for(int j=0; j<edges.size(); j++) {
      u = edges[j]->u;
      v = edges[j]->v;
      w = edges[j]->w;
      /* printf("%d: %d %d %d\n",i,u,v,w); */
      relax(u, v, w);
    }
}

void printDis(int n)
{
  for(int i=1; i<=n; i++)
    printf("%d ", dis[i]);
  putchar('\n');
}

Tuple *make_tuple(int u, int v, int w)
{
  Tuple *t = (Tuple*)malloc(sizeof(Tuple));
  t->u = u;
  t->v = v;
  t->w = w;
  return t;
}

int main()
{
  int T, N;
  scanf("%d %d", &T, &N);
  for(int t=0; t<T; t++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edges.push_back(make_tuple(u, v, w));
  }
  BellmanFord(N, N);
  /* printDis(N); */
  printf("%d\n", dis[1]);
}
