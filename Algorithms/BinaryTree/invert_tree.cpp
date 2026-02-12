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
   TreeNode* invertTree(TreeNode* root) {
       if(root==NULL) return NULL;

       root->left=invertTree(root->left);
       root->right= invertTree(root->right);

       TreeNode* t=root->left;
       root->left=root->right;
       root->right=t;

       return root;
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
    sol.invertTree(root);
    return 0;
}
