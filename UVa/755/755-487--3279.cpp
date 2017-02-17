#include<bits/stdc++.h>
using namespace std;
map<string, int> book;
int main()
{
  int n, m;
  char c;
  scanf("%d", &n);
  string str("0000000");
  string trush;
  while(n--) {
    book.clear();
    scanf("%d\n", &m);
    for(int i=0; i<m; i++) {
      int j=0;
      while((c=getchar())!='\n' && j<7) {
        if(c>='A'&&c<='Z' && c!='Q' && c!='Z') {
          if(c>='A'&&c<='C') c='2';
          else if(c>='D'&&c<='F') c='3';
          else if(c>='G'&&c<='I') c='4';
          else if(c>='J'&&c<='L') c='5';
          else if(c>='M'&&c<='O') c='6';
          else if(c>='P'&&c<='S') c='7';
          else if(c>='T'&&c<='V') c='8';
          else if(c>='W'&&c<='Y') c='9';
          str[j++]=c;
        } else if(c>='0'&&c<='9') {
          str[j++]=c;
        }
      }
      if(c!='\n') getline(cin, trush);
      //	string str(n);
      if(book.find(str) == book.end()) book[str] = 1;
      else book[str]++;
    }
    if(book.size()==m)
      cout << "No duplicates.\n";
    else
      for(map<string, int>::iterator it=book.begin(); it!=book.end(); it++)
        if(it->second>1)
          cout << it->first.substr(0, 3) << '-' << it->first.substr(3, 4) << ' ' << it->second << '\n';
    if(n>0) cout << '\n';
  }
}
