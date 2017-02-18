#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

char dungeon[35][35][35];
bool visited[35][35][35];
vector<int> start;
queue<vector<int> > q;

bool end = false;
int mv = 0;

void Init();
void GetDun(int,int,int);
void ClearDun(int,int,int);
bool Move(int,int,int,int);
void PrintDun(int,int,int);

int main()
{
  int L, R, C;
  int x, y, z;
  vector<int> now;
  Init();
  while(scanf("%d %d %d\n", &L, &R, &C) && !(L==0 && R==0 && C==0)) {
    GetDun(L,R,C);
    q.push(start);
    bool remain = false;
    while(!q.empty()) {
      now = q.front();
      q.pop();
      x=now[0]; y=now[1]; z=now[2];
      // North
      if(remain=Move(x, y+1, z, now[3]+1)) break;
      // South
      if(remain=Move(x, y-1, z, now[3]+1)) break;
      // East
      if(remain=Move(x, y, z+1, now[3]+1)) break;
      // West
      if(remain=Move(x, y, z-1, now[3]+1)) break;
      // Up
      if(remain=Move(x+1, y, z, now[3]+1)) break;
      // Down
      if(remain=Move(x-1, y, z, now[3]+1)) break;
    }
    if(!remain && q.empty()) printf("Trapped!\n");
    ClearDun(L,R,C);
  }
}

void Init()
{
  for(int i=0; i<35; i++)
    for(int j=0; j<35; j++)
      for(int k=0; k<35; k++) {
        dungeon[i][j][k] = '#';
        visited[i][j][k] = false;
      }
}

void GetDun(int l, int r, int c)
{
  for(int i=1; i<=l; i++) {
    for(int j=1; j<=r; j++) {
      for(int k=1; k<=c; k++) {
        dungeon[i][j][k] = getchar();
        if(dungeon[i][j][k]=='S') {
          int s[] = {i, j, k, 0};
          start.insert(start.begin(), s, s+4);
          visited[i][j][k] = true;
        }
      }
      getchar();
    }
    getchar();
  }
}

void ClearDun(int l, int r, int c)
{
  for(int i=1; i<=l; i++)
    for(int j=1; j<=r; j++)
      for(int k=1; k<=c; k++) {
        dungeon[i][j][k] = '#';
        visited[i][j][k] = false;
      }
  while(!q.empty()) q.pop();
}

bool Move(int x, int y, int z, int c)
{
  if(!visited[x][y][z] && dungeon[x][y][z] != '#') {
    if(dungeon[x][y][z] == 'E') {
      printf("Escaped in %d minute(s).\n", c);
      return true;
    } else {
      visited[x][y][z] = true;
      int nxt[] = {x, y, z, c};
      vector<int> next(nxt, nxt+sizeof(int)*4);
      q.push(next);
    }
  }
  return false;
}

void PrintDun(int l, int r, int c)
{
  for(int i=1; i<=l; i++) {
    for(int j=1; j<=r; j++) {
      for(int k=1; k<=c; k++)
        putchar(dungeon[i][j][k]);
      putchar('\n');
    }
    putchar('\n');
  }
}
