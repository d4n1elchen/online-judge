#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

const int maxLine = 1000;
vector<string> lines[maxLine];
vector<int> maxLength;

int main()
{
  string s;
  int l = 0;
  while(getline(cin, s)) {
    stringstream ss(s);
    string word;
    int c = 0;
    while(ss >> word) {
      lines[l].push_back(word);
      int now = word.size();
      try
      {
        int prev = maxLength.at(c);
        maxLength.at(c) = now > prev ? now : prev;
      } catch(const out_of_range& oor) {
        maxLength.push_back(now);
      }
      c++;
    }
    l++;
  }
  for(int i = 0; i < l; i++) {
    int sz = lines[i].size();
    for(int j = 0; j < sz; j++) {
      int len = j<sz-1 ? maxLength[j]+1 : 0;
      printf("%-*s", len, lines[i][j].c_str());
    }
    cout << endl;
  }
}
