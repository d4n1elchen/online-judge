#include<string>
#include<map>
#include<iostream>
#include<vector>
#define MAX 150
using namespace std;

map<string, int> m;
vector<string> v;
int v1[MAX], v2[MAX];
int LCS[MAX][MAX], PREV[MAX][MAX];

void init() {
  for(int i=0; i<MAX; i++) {
    for(int j=0; j<MAX; j++) {
      LCS[i][j] = 0;
      PREV[i][j] = 0;
    }
    v1[i] = 0;
    v2[i] = 0;
  }
}

void lcs(int M, int N) {
  for(int i=1; i<=M; i++) {
    for(int j=1; j<=N; j++) {
      if(v1[i-1] == v2[j-1]) {
        LCS[i][j] = LCS[i-1][j-1]+1;
        PREV[i][j] = -1;
      } else {
        if(LCS[i-1][j] > LCS[i][j-1]) {
          LCS[i][j] = LCS[i-1][j];
          PREV[i][j] = 1;
        } else {
          LCS[i][j] = LCS[i][j-1];
          PREV[i][j] = 2;
        }
      }
    }
  }
}

int main()
{
  string s;
  while(cin >> s) {
    init();
    m.clear();
    v.clear();
    int c = 0, M = 0, N = 0;
    if(m.find(s) == m.end()) {
      m[s] = c++;
      v.push_back(s);
    }
    v1[M++] = m[s];
    while(cin >> s && s != "#") {
      if(m.find(s) == m.end()) {
        m[s] = c++;
        v.push_back(s);
      }
      v1[M++] = m[s];
    }
    while(cin >> s && s != "#") {
      if(m.find(s) == m.end()) {
        m[s] = c++;
        v.push_back(s);
      }
      v2[N++] = m[s];
    }
    /* for(int i=0; i<M; i++) cout<<v[v1[i]]<<' '; */
    /* cout <<'\n'; */
    /* for(int i=0; i<N; i++) cout<<v[v2[i]]<<' '; */
    /* cout <<'\n'; */
    lcs(M, N);
    /* for(int i=0; i<=M; i++) { */
    /*   for(int j=0; j<=N; j++) { */
    /*     cout << PREV[i][j] << ' '; */
    /*   } */
    /*   cout << '\n'; */
    /* } */
    int now = 9, i=M, j=N;
    vector<string> temp;
    while(now && i && j) {
      now = PREV[i][j];
      if(now < 0) {
        i--; j--;
        temp.push_back(v[v1[i]]);
      } else if(now == 1) i--;
      else if(now == 2) j--;
    }
    for(int i=temp.size()-1; i>0; i--) cout << temp[i] << ' ';
    cout << temp[0] << '\n';
  }
}
