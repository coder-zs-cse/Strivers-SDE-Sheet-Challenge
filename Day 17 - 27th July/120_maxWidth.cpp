#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    int maxWidth = 1;
    while(!q.empty()){
        int size = q.size();
        maxWidth = max(maxWidth,size);
        for(int i=0;i<size;i++){
            TreeNode<int>* current = q.front();
            q.pop();
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }

    }
    return maxWidth;

}