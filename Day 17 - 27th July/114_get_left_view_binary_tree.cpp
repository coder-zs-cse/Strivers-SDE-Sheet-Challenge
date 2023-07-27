#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    if(!root) return {};
    queue<TreeNode<int>*> q;
    q.push(root);
    vector<int> output;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode<int> *current = q.front();
            q.pop();
            if(i==0) output.push_back(current->data);
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
    }
    return output;
}