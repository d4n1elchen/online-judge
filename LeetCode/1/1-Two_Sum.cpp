class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> table;
      vector<int> result;
      vector<int>::iterator it = nums.begin();
      for(; it != nums.end(); ++it) {
        int index = it-nums.begin();
        int num = *it;
        int remain = target - num;
        if(table.find(num) != table.end()) {
          result.push_back(table[num]);
          result.push_back(index);
          break;
        } else {
          table[remain] = index;
        }
      }
      return result;
    }
};
