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
     void check(TreeNode* r,int t, vector<vector<int>>&v,vector<int>&p)
    {
        if(!r) return ;
        p.push_back(r->val);
        if(!(r->left)&&!(r->right)&& t==r->val)
            v.push_back(p);
        check(r->left,t-r->val,v,p);
        check(r->right,t-r->val,v,p);
        p.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>>v;
        vector<int>p;
        check(root,t,v,p);
        return v;
 
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
    auto paths = sol.pathSum(root, 7);
    for (const auto& p : paths) {
        cout << "[";
        for (size_t i = 0; i < p.size(); ++i) {
            cout << p[i];
            if (i + 1 < p.size()) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
