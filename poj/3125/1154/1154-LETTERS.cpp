#include<cstdio>
#include<cstring>

char board[40][40];
int r, c, max=0;

void Move(int m, int i, int j, bool visited[35])
{
  if(m>max) max=m;
  char now = board[i][j];
  bool vis[35];
  memcpy(vis, visited, sizeof(bool)*35);
  vis[now-'A'] = true;
  // up
  if(i>0 && !vis[board[i-1][j]-'A']) Move(m+1, i-1, j, vis);
  // down
  if(i<r-1 && !vis[board[i+1][j]-'A']) Move(m+1, i+1, j, vis);
  // left
  if(j>0 && !vis[board[i][j-1]-'A']) Move(m+1, i, j-1, vis);
  // right
  if(j<c-1 && !vis[board[i][j+1]-'A']) Move(m+1, i, j+1, vis);
}

int main() {
  bool visited[35]={false};
  scanf("%d %d\n", &r, &c);
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++)
      board[i][j] = getchar();
    getchar();
  }
  /* printf("%d %d\n", r, c); */
  /* for(int i=0; i<r; i++) { */
  /*   for(int j=0; j<c; j++) */
  /*     putchar(board[i][j]); */
  /*   putchar('\n'); */
  /* } */
  Move(1, 0, 0, visited);
  printf("%d\n", max);
}
