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
   vector<string>a;
    void dfs(TreeNode* r, string s)
    {
        if(r==NULL) return;

        s+=to_string(r->val);
        if(r->left ==NULL && r->right ==NULL) 
        {
            a.push_back(s);
            return;
        }

       if(r->left) dfs(r->left , s+"->");
       if(r->right) dfs(r->right,s+"->");

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        a.clear();
        dfs(root,"");
        return a;
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
    vector<string> paths = sol.binaryTreePaths(root);
    for(const string& path : paths) {
        cout << path << endl;
    }
    return 0; 
}
