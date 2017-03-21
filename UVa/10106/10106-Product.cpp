#include<string>
#include<iostream>
#include<vector>

const int MAX = 100000;

using namespace std;

vector<int> num1;
vector<int> num2;
vector<int> result;

void carry()
{
  int sz = result.size();
  for(int i=0; i<sz; i++) {
    if(i==sz-1 && result[i]/10) result.resize(sz+1);
    result[i+1] += result[i]/10;
    result[i] %= 10;
  }
}

int main()
{
  string s1, s2;
  while(getline(cin, s1)) {
    num1.clear(); num2.clear(); result.clear();

    getline(cin, s2);
    for(string::iterator it=s1.end()-1; it>=s1.begin(); it--) num1.push_back(*it-'0');
    for(string::iterator it=s2.end()-1; it>=s2.begin(); it--) num2.push_back(*it-'0');

    if( (num1.size()==1 && num1[0]==0) || (num2.size()==1 && num2[0]==0) ) {
      result.resize(1);
      result[0] = 0;
    } else {
      result.resize(num1.size()+num2.size()-1);
      for(int i=0; i<num1.size(); ++i)
        for(int j=0; j<num2.size(); ++j)
          result[i+j] += num1[i] * num2[j];
    }

    carry();

    for(int i=result.size()-1; i>=0; --i) cout << result[i];
    cout << '\n';
  }
}
