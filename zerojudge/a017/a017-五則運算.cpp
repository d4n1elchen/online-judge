#include<iostream>
#include<string>
#include<sstream>
#include<stack>
using namespace std;

long long int calc(stringstream &ss) {
  long long int a, b;
  string s;
  stack<long long int> num, rnum;
  stack<string> op, rop;
  while(ss >> s) {
    if(s=="(") num.push(calc(ss));
    else if(s==")") break;
    else if(s=="*" || s=="/" || s=="%") {
      string st;
      ss >> st;
      if(st=="(") b=calc(ss);
      else b=stoi(st);
      a=num.top();
      num.pop();
      if(s=="*") num.push(a*b);
      else if(s=="/") num.push(a/b);
      else if(s=="%") num.push(a%b);
    } else if(s=="+" || s=="-"){
      op.push(s);
    } else num.push(stoi(s));
    /* if(num.top()<0) cout << num.top() << endl; */
  }
  while(!num.empty()) {rnum.push(num.top()); num.pop();}
  while(!op.empty()) {rop.push(op.top()); op.pop();}
  while(!rop.empty()) {
    s = rop.top();
    rop.pop();
    a = rnum.top();
    rnum.pop();
    b = rnum.top();
    rnum.pop();
    if(s=="+") rnum.push(a+b);
    else if(s=="-") rnum.push(a-b);
  }
  return rnum.top();
}

int main()
{
  string str;
  while(getline(cin, str)) {
    stringstream ss(str);
    cout << calc(ss) << endl;
  }
}
