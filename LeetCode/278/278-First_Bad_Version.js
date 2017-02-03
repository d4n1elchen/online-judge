/**
 * Definition for isBadVersion()
 *
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
      var s=0, e=n;
      while(e-s>1) {
        n = s+Math.floor((e-s)/2);
        if(isBadVersion(n)) e=n;
        else s=n;
      }
      return e;
    };
};
