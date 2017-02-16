#include<cstdio>

const float dh = 0.5;
const float dm = 6;

int main() {
  int h, m;
  int mm;
  float hd, md, d;
  while(scanf("%d:%d", &h, &m)) {
    if(h==0&&m==0) return 0;
    mm = h*60 + m;
    hd = mm*dh;
    md = m*dm;
    d = hd-md;
    if(d>180) d=360-d;
    else if(d<-180) d=360+d;
    else if(d<0) d=-d;
    printf("%.3f\n", d);
  }
  return 0;
}
