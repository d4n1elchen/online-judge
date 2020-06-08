/*
 * @lc app=leetcode id=346 lang=cpp
 *
 * [346] Moving Average from Data Stream
 *
 * https://leetcode.com/problems/moving-average-from-data-stream/description/
 *
 * algorithms
 * Easy (70.07%)
 * Likes:    527
 * Dislikes: 56
 * Total Accepted:    118.1K
 * Total Submissions: 168.4K
 * Testcase Example:  '["MovingAverage","next","next","next","next"]\n[[3],[1],[10],[3],[5]]'
 *
 * Given a stream of integers and a window size, calculate the moving average
 * of all integers in the sliding window.
 * 
 * Example:
 * 
 * 
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
 * 
 * 
 * 
 * 
 */

// @lc code=start
class MovingAverage {
private:
    queue<int> window;
    double sum = 0;
    int size;
public:
    /** Initialize your data structure here. */
    MovingAverage(int _size) : size(_size) {
        
    }
    
    double next(int val) {
        window.push(val);
        sum += val;
        if (window.size() > size) {
            sum -= window.front();
            window.pop();
        }
        return sum / window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
// @lc code=end
