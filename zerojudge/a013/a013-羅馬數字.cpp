#include<string>
#include<iostream>
#include<sstream>
using namespace std;

int map(char c)
{
  switch(c) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
  }
}

int romtoi(string r)
{
  int sum = 0, cnt = 0;
  for(string::iterator it=r.begin(); it!=r.end(); it++) {
    sum += map(*it);
    if((it+1)!=r.end() && map(*(it+1)) > map(*it)) {
      sum = map(*(it+1))-sum;
      return sum + romtoi(string(it+2, r.end()));
    } else if((it+1)!=r.end() && map(*(it+1)) < map(*it)) {
      return sum + romtoi(string(it+1, r.end()));
    } else {
      cnt++;
    }
  }
  return sum;
}

string _itorom(int i, int base, char c, char d, char e)
{
  int k=0, l=0, m=0;
  string rt;
  while(i/base > 0) {
    k++;
    if(base>1)
      i-=base;
    else
      i--;
    if(k==4){
      k=-1;
      if(l) m=1;
      l=!l;
    }
  }
  if(m) {
    rt.push_back(c);
    rt.push_back(e);
  } else if(l) {
    if(k<0) {
      rt.push_back(c);
      rt.push_back(d);
    } else {
      rt.push_back(d);
      for(int j=0; j<k; j++)
        rt.push_back(c);
    }
  } else {
    for(int j=0; j<k; j++)
      rt.push_back(c);
  }
  return rt;
}

string itorom(int i)
{
  string r;
  if(!i) return "ZERO";
  else {
    for(int j=0; j<i/1000; j++)
      r.push_back('M');
    i %= 1000;

    r += _itorom(i, 100, 'C', 'D', 'M');
    i %= 100;
    r += _itorom(i, 10, 'X', 'L', 'C');
    i %= 10;
    r += _itorom(i, 1, 'I', 'V', 'X');
    return r;
  }
}

int main()
{
  string str;
  while(getline(cin, str) && str!="#") {
    stringstream ss(str);
    string rnum1, rnum2;
    int sub=0;

    ss >> rnum1 >> rnum2;
    sub = romtoi(rnum1) - romtoi(rnum2);
    sub = sub>=0? sub: -sub;

    cout << itorom(sub) << '\n';
  }
}
