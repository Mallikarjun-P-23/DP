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
    int getleft(TreeNode* root){
        int h = 0;
        while(root){
            h++;
            root = root->left;
        }
        return h;
    }

    int getright(TreeNode* root){
        int h = 0;
        while(root){
            h++;
            root = root->right;
        }
        return h;
    }

public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = getleft(root);
        int rh = getright(root);

        // Perfect binary tree
        if(lh == rh){
            return (1LL << lh) - 1;
        }

        // Otherwise recurse
        return countNodes(root->left) + countNodes(root->right) + 1;
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
    cout << "Total nodes: " << sol.countNodes(root) << endl;

    return 0;
}
