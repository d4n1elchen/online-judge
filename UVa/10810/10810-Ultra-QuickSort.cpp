#include<cstdio>

int a[500100];
int buf[500100];
int n;
long long op;

void printArr(int s, int e) {
  for (int i = s; i < e; i++) printf("%d ", a[i]);
  putchar('\n');
}

void merge(int s1, int e1, int s2, int e2) {
  int s = s1;
  int len = e2-s1;
  for (int i = 0; i < len; i++) {
    if (s2 == e2) {
      buf[i] = a[s1++];
    } else if (s1 == e1) {
      buf[i] = a[s2++];
    } else if (a[s2] < a[s1]) {
      op += s2-s-i;
      buf[i] = a[s2++];
    } else {
      buf[i] = a[s1++];
    }
  }
  for (int i = 0; i < len; i++) {
    a[s+i] = buf[i];
  }
}

void merge_sort(int start, int end) {
  if (start < end-1) {
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, mid, mid, end);
  }
}

int main() {
  while (scanf("%d", & n)) {
    if (n == 0) return 0;
    for (int i = 0; i < n; i++) scanf("%d", & a[i]);
    op = 0;
    merge_sort(0, n);
    printf("%lld\n", op);
  }
  return 0;
}
