class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int sz = s.size();
      map<char, int> appear;
      int start, end, maxlen = 0;
      int i, j;
      char c;
      for(i = 0; i < sz; i++) {
        start = i;
        appear.clear();
        for(j = i; j < sz; j++) {
          c = s[j];
          if(appear.find(c) == appear.end()) {
            appear[c] = j;
            if(j == sz-1) {
              end = sz;
              i = j;
            }
          } else {
            if(appear[c] == start) {
              start++;
              appear[c] = j;
              if(j == sz-1) {
                end = sz;
                i = j;
              }
              continue;
            }
            end = j;
            i = appear[c];
            break;
          }
        }
        if(maxlen < (end-start)) maxlen = end-start;
      }
      return maxlen;
    }
};
