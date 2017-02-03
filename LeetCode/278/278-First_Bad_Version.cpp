// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      int a = 1, b = n;
      bool bn, bn1;
      n = a+(b-a)/2;
      while(a <= b) {
        bn = isBadVersion(n);
        bn1 = isBadVersion(n-1);
        if(bn && !bn1) break;
        if(bn)
          b = n - 1;
        else
          a = n + 1;
        n = a+(b-a)/2;
      }
      return n;
    }
};
