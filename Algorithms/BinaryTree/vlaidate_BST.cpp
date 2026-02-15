#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool check(TreeNode* a , long long m1,long long m2)
    {
      if (!a) return true;
        if (a->val <= m1 || a->val >=m2)
            return false;

        return check(a->left, m1, a->val) and
               check(a->right, a->val, m2);
       
        
    }
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    /*
        Example Tree:
                1
               / \
              2   3
             / \  /
            4  5 6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;
    cout << sol.isValidBST(root) << endl;
    return 0;
}
