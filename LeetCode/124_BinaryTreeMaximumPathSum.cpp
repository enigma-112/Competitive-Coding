 int find_ans(TreeNode * root, int &finalans){
        
         if(root==NULL){
            return 0;
        }
        int maxleft  = find_ans(root->left,finalans);
        int maxright = find_ans(root->right,finalans);
        int singlemax = max(root->val,max(root->val+maxleft,root->val+maxright));
        int ans = max(singlemax,maxleft+maxright+root->val);
        finalans=max(finalans,ans);
        return singlemax;
    }
    int maxPathSum(TreeNode* root) {
        
        int finalans=INT_MIN;
        find_ans(root,finalans);
        return finalans;
        
        
    }