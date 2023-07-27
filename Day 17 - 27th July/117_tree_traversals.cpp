#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void traverse(BinaryTreeNode<int> *root,vector<vector<int>> &output){
    if(!root) return;
    output[1].push_back(root->data);
    traverse(root->left,output);
    output[0].push_back(root->data);
    traverse(root->right,output);
    output[2].push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> output;
    output.push_back({});
    output.push_back({});
    output.push_back({});
    traverse(root,output);
    return output;
}