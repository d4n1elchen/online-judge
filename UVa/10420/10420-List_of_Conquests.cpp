#include<map>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

map<string, int> m;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while(n--) {
    string str, country;
    cin >> str;
    country = str.substr(0, str.find(' '));
    if(m.find(country) == m.end()) m[country] = 1;
    else m[country]++;
    getline(cin, str);
  }
  for(map<string, int>::iterator it = m.begin(); it != m.end(); it++) cout << it->first << ' ' << it->second << '\n';
}
