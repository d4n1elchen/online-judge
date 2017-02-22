#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>

const int sz = 1100;
int res[sz]={0};
int a[sz]={0};
int b[sz]={0};

int Size(int arr[sz]) {
  int i = sz;
  while(i--) if(arr[i] == 0) continue; else return i+1;
}

int Add(int a[sz], int i, int b[sz], int j, int res[sz]) {
  int k = 0;
  int c = 0;
  while(i && j) {
    res[k] = a[k] + b[k] + c;
    if(res[k]>9) {
      c = 1;
      res[k] %= 10;
    } else c = 0;
    i--; j--; k++;
  }
  if(i) {
    while(i) {
      res[k] = a[k] + c;
      if(res[k]>9) {
        c = 1;
        res[k] %= 10;
      } else c = 0;
      i--; k++;
    }
  }
  if(j) {
    while(j) {
      res[k] = b[k] + c;
      if(res[k]>9) {
        c = 1;
        res[k] %= 10;
      } else c = 0;
      j--; k++;
    }
  }
  if(c && k<sz) {
    res[k] = c;
    k++;
  }
  return k;
}

void reverse(int rev[sz], int arr[sz], int n) {
  int i, j;
  for(i=n-1, j=0; i>=0; i--, j++) rev[j] = arr[i];
  return;
}

int Comp(int arr[sz], int comp[sz]) {
  for(int j=0; j<sz; j++) comp[j] = 9-arr[j];
  int one[sz];
  one[0] = 1;
  return Add(comp, sz, one, 1, comp);
}

void printArr(int arr[sz], int n) {
  if(arr[sz-1]==9){
    Comp(arr, arr);
    putchar('-');
  }
  bool zero = true;
  while(n--) {
    if(arr[n]==0 && zero) continue;
    else zero = false;
    printf("%d", arr[n]);
  }
  if(zero) putchar('0');
  putchar('\n');
}

int Compare(int a[sz], int i, int b[sz], int j) {
  /* printArr(a, i); */
  /* printArr(b, j); */
  if(i>j) return 1;
  else if(i<j) return -1;
  else {
    while(i--) {
      if(a[i]>b[i]) return 1;
      else if(a[i]<b[i]) return -1;
    }
  }
  return 0;
}

int Sub(int a[sz], int i, int b[sz], int j, int res[sz]) {
  int k = Comp(b, b);
  return Add(a, i, b, k, res);
}

int ShiftLeft(int arr[sz], int i, int l) {
  int k = i+l;
  while(i--) {
    arr[i+l] = arr[i];
    arr[i] = 0;
  }
  return k;
}

int MulC(int a[sz], int i, int m, int res[sz]) {
  int k = 0, c = 0;
  while(i--) {
    res[k] = a[k] * m + c;
    c = res[k] / 10;
    res[k] %= 10;
    k++;
  }
  if(c) {
    res[k] = c;
    k++;
  }
  return k;
}

/* int Mul(int a[sz], int i, int b[sz], int j, int res[sz]) { */
/*   for(int k=0; k<i; k++) { */
/*     res[k] = a[k]; */
/*   } */
/*   int temp[sz] = {0}; */
/*   temp[0] = 1; */
/*   int l =  Add(res, 0, a, i, res); */
/*   while(Sub(b, j, temp, 1, b) && Size(b)) { */
/*     int l = Add(res, l, a, i, res); */
/*   } */
/*   return l; */
/* } */

int Mul(int a[sz], int i, int b[sz], int j, int res[sz]) {
  int l;
  for(int k=0; k<sz; k++) {
    res[k] = 0;
  }
  if(i<j) {
    for(int k=0; k<i; k++) {
      int temp[sz] = {0};
      l = MulC(b, j, a[k], temp);
      if(k)
        l = ShiftLeft(temp, l, k);
      Add(res, l, temp, l, res);
    }
  } else {
    for(int k=0; k<j; k++) {
      int temp[sz];
      l = MulC(a, i, b[k], temp);
      if(k)
        l = ShiftLeft(temp, l, k);
      Add(res, l, temp, l, res);
    }
  }
  return l;
}

int ShiftRight(int arr[sz], int i, int l) {
  int k = i-l;
  for(int j=l; j<i; j++) {
    arr[j-l] = arr[j];
    arr[j] = 0;
  }
  return k;
}

int DivC(int a[sz], int i, int b[sz], int j) {
  for(int k=9; k>=0; k--) {
    int temp[sz] = {0};
    int temp2[sz];
    temp[0] = k;
    int l = Mul(b, i, temp, 1, temp2);
    if(Compare(a, i, temp2, l) >= 0) {
      Sub(a, i, temp2, l, a);
      return k;
    }
  }
}

int Div(int a[sz], int i, int b[sz], int j, int res[sz]) {
  for(int k=0; k<sz; k++) {
    res[k] = 0;
  }
  if(j>i) return 0;
  int tb[sz] = {0};
  memcpy(tb, b, j*sizeof(int));
  int tj = j;
  if(i-j)
    tj = ShiftLeft(tb, j, i-j);
  for(int k=i-j; k>=0; k--) {
    res[k] = DivC(a, i, tb, tj);
    tj = ShiftRight(tb, tj, 1);
  }
  return sz;
}

void Init() {
  for(int i=0; i<sz; i++) {
    a[i] = 0;
    b[i] = 0;
    res[i] = 0;
  }
}

int main()
{
  char c, op;
  while((c=getchar())!=EOF) {
    int i, j, k;
    int ta[sz]={0};
    int tb[sz]={0};
    Init();
    i = 0; j = 0;
    ta[i++] = c-'0';
    while((c=getchar())!=' ') ta[i++] = c-'0';
    op=getchar();
    getchar(); // ' '
    while((c=getchar())!='\n') tb[j++] = c-'0';
    reverse(a, ta, i);
    reverse(b, tb, j);
    /* printArr(a, i); */
    /* putchar(op); */
    /* putchar('\n'); */
    /* printArr(b, j); */
    if(op=='+') {
      k = Add(a, i, b, j, res);
    } else if(op=='-') {
      k = Sub(a, i, b, j, res);
    } else if(op=='*') {
      k = Mul(a, i, b, j, res);
    } else if(op=='/') {
      k = Div(a, i, b, j, res);
    }
    printArr(res, k);
  }
}
