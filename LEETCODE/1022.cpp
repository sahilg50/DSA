class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(! root) return 0;
        
        int ans = 0, currNum=0;
        stack<pair<TreeNode*,int>> S;
        S.push({root,0});
        
        while(!S.empty()) {
            auto p = S.top(); S.pop();
            root = p.first;
            currNum = p.second;
            
            // Equivalent to left shift by 1 and then ORing by cur->val.
            currNum = currNum*2 + root->val;
            
            if(!root->left && !root->right)
                ans += currNum;
            
            if(root->left) S.push({root->left, currNum});
            if(root->right) S.push({root->right, currNum});
        }
        
        return ans;
        
    }
};