#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int, int>> s;

int main()
{
  int n;
  while(scanf("%d", &n) && n) {
    int origin, target;
    bool yes = true;
    s.clear();
    for(int i = 0; i < n; i++) {
      scanf("%d %d", &origin, &target);
      s.push_back(make_pair(origin, target));
    }
    vector<pair<int, int>> fs(s);
    sort(fs.begin(), fs.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
        if(left.first != right.first) return left.first < right.first;
        else return left.second < right.second;
        });
    vector<pair<int, int>> ss(s);
    sort(ss.begin(), ss.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
        if(left.second != right.second) return left.second < right.second;
        else return left.first < right.first;
        });
    vector<pair<int, int>>::iterator fit, sit;
    for(fit = fs.begin(), sit = ss.begin(); fit != fs.end(); ++fit, ++sit) {
      if((fit->second != sit->first) || (fit->first != sit->second)) {
        yes = false;
        break;
      }
    }
    if(yes) printf("YES\n");
    else printf("NO\n");
  }
}
