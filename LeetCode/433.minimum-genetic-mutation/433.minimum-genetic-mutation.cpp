/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 *
 * https://leetcode.com/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (41.08%)
 * Likes:    390
 * Dislikes: 52
 * Total Accepted:    30.2K
 * Total Submissions: 73K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * A gene string can be represented by an 8-character long string, with choices
 * from "A", "C", "G", "T".
 * 
 * Suppose we need to investigate about a mutation (mutation from "start" to
 * "end"), where ONE mutation is defined as ONE single character changed in the
 * gene string.
 * 
 * For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
 * 
 * Also, there is a given gene "bank", which records all the valid gene
 * mutations. A gene must be in the bank to make it a valid gene string.
 * 
 * Now, given 3 things - start, end, bank, your task is to determine what is
 * the minimum number of mutations needed to mutate from "start" to "end". If
 * there is no such a mutation, return -1.
 * 
 * Note:
 * 
 * 
 * Starting point is assumed to be valid, so it might not be included in the
 * bank.
 * If multiple mutations are needed, all mutations during in the sequence must
 * be valid.
 * You may assume start and end string is not the same.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * start: "AACCGGTT"
 * end:   "AACCGGTA"
 * bank: ["AACCGGTA"]
 * 
 * return: 1
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * start: "AACCGGTT"
 * end:   "AAACGGTA"
 * bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
 * 
 * return: 2
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * start: "AAAAACCC"
 * end:   "AACCCCCC"
 * bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
 * 
 * return: 3
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    char genes[4] = {'A', 'T', 'C', 'G'};
public:
    int minMutation(string start, string end, vector<string>& _bank) {
        unordered_set<string> bank(_bank.begin(), _bank.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(start);
        int lvl = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size --> 0) {
                string s = q.front(); q.pop();
                //cout << s << endl;
                if (s == end) return lvl;
                for (int i=0; i<s.size(); ++i) {
                    string stmp = s;
                    for (char g : genes) {
                        if (s[i] == g) continue;
                        stmp[i] = g;
                        if (bank.count(stmp) == 1 && visited.count(stmp) == 0) {
                            visited.insert(stmp);
                            q.push(stmp);
                        }
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};
// @lc code=end
