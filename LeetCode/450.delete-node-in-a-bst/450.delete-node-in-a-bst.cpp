/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 *
 * https://leetcode.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (42.52%)
 * Likes:    1706
 * Dislikes: 82
 * Total Accepted:    109.2K
 * Total Submissions: 255.7K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * Given a root node reference of a BST and a key, delete the node with the
 * given key in the BST. Return the root node reference (possibly updated) of
 * the BST.
 * 
 * Basically, the deletion can be divided into two stages:
 * 
 * Search for a node to remove.
 * If the node is found, delete the node.
 * 
 * 
 * 
 * Note: Time complexity should be O(height of tree).
 * 
 * Example:
 * 
 * root = [5,3,6,2,4,null,7]
 * key = 3
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Given key to delete is 3. So we find the node with value 3 and delete it.
 * 
 * One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 4   6
 * ⁠/     \
 * 2       7
 * 
 * Another valid answer is [5,2,6,null,4,null,7].
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 2   6
 * ⁠  \   \
 * ⁠   4   7
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* parent = NULL;
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (key > root->val) {
            parent = root;
            deleteNode(root->right, key);
            return root;
        } else if (key < root->val) {
            parent = root;
            deleteNode(root->left, key);
            return root;
        }

        TreeNode *newRoot, *right;
        right = newRoot = root->right;

        if (newRoot == NULL) {
            newRoot = root->left;
        } else {
            while (right->left != NULL) right = right->left;
            right->left = root->left;
        }

        if (parent != NULL) {
            if (key > parent->val) parent->right = newRoot;
            else parent->left = newRoot;
        }

        return newRoot;
    }
};
// @lc code=end
