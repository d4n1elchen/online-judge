/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  var t = {};
  for(var i = 0; i < nums.length; i++) {
    var r = target-nums[i];
    if(typeof t[r] != 'undefined') return [t[r], i];
    else t[nums[i]] = i;
  }
};
