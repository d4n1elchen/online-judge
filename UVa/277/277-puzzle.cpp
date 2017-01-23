#include<stdio.h>
#include<string.h>

char frame[7][7];
int nx = 0, ny = 0;

void printFrame()
{
  for(int i = 1; i <= 5; i++) {
    for(int j = 1; j <= 5; j++) {
      printf("%c", frame[i][j]);
      j < 5 ? putchar(' ') : putchar('\n');
    }
  }
}

void initFrame()
{
  for(int i = 0; i < 7; i++) {
    for(int j = 0; j < 7; j++) {
      frame[i][j] = '.';
    }
  }
}

bool move(int dx, int dy)
{
  int x = nx + dx;
  int y = ny + dy;
  if(frame[x][y] == '.') return false;
  else {
    char t = frame[x][y];
    frame[x][y] = ' ';
    frame[nx][ny] = t;
    nx = x;
    ny = y;
    return true;
  }
}

int main()
{
  char w;
  int k = 0;
  while((w=getchar()) != 'Z') {
    initFrame();
    int i = 1, j = 1;
    nx = 0, ny = 0;
    frame[i][j] = w;
    if(w == ' ') {
      nx=i;
      ny=j;
    }
    j++;
    for(; i <= 5; i++) {
      for(w=getchar(); j <= 5; j++, (w=getchar())) {
        frame[i][j] = w;
        if(w == ' ') {
          nx=i;
          ny=j;
        }
      }
      j = 1;
    }
    /* printFrame(); */
    bool b = true;
    while((w=getchar()) != '0') {
      /* printf("%c", w); */
      int dx = 0, dy = 0;
      switch(w) {
        case 'A':
          dx = -1;
          break;
        case 'B':
          dx = 1;
          break;
        case 'R':
          dy = 1;
          break;
        case 'L':
          dy = -1;
          break;
        case '\n':
          break;
        default:
          b = false;
      }
      b = b && move(dx, dy);
    }
    getchar();
    if(k > 0) putchar('\n');
    printf("Puzzle #%d:\n", ++k);
    if(b) printFrame();
    else printf("This puzzle has no final configuration.\n");
  }
  return 0;
}
