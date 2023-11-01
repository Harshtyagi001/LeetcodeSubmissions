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
public:
   vector<int>ans;
   int maxi=0,crr=0,prev=INT_MIN;
   void solve(TreeNode*root){
       if(!root)return;
       
       solve(root->left);
       if(root->val!=prev){
            crr=1;
            prev=root->val;
       }
       else{
           crr++;
       }

       if(crr>maxi){
           maxi=crr;
           ans={root->val};
       }else if(crr==maxi){
           ans.push_back(root->val);
       }

       solve(root->right);
   }

    vector<int> findMode(TreeNode* root) {
        solve(root);
        return ans;
    }
};