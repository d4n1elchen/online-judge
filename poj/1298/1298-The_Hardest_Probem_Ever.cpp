#include<iostream>
#include<string>
using namespace std;

int main()
{
  string str;
  string::iterator it;
  char c;
  while(getline(cin, str)) {
    if(!str.compare("ENDOFINPUT")) return 0;
    else if(!str.compare("END")) continue;
    else if(!str.compare("START")) {
      getline(cin, str);
      for( it = str.begin(); it < str.end(); ++it ) {
        c = *it;
        if(c >= 'A' && c <= 'Z') {
          c = c-5;
          if(c < 'A') c += 26;
        }
        *it = c;
      }
      cout << str << endl;
    }
  }
  return 0;
}
