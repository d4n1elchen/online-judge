#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

stack<char> stk;

int main()
{
  int n;
  string str;
  scanf("%d\n", &n);
  while(n--) {
    bool remain = false;
    getline(cin, str);
    for(char &c : str) {
      if(c=='(' || c=='[') stk.push(c);
      else if(stk.empty()) {
        remain = true;
        break;
      } else {
        if(c==')' && stk.top()=='(') stk.pop();
        else if(c==']' && stk.top()=='[') stk.pop();
        else {
          remain = true;
          break;
        }
      }
    }
    if(stk.empty() && !remain) printf("Yes\n");
    else {
      printf("No\n");
      while(!stk.empty()) stk.pop();
    }
  }
}
