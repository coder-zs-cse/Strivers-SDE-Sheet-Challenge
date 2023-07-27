#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

*************************************************************/
void preorder(BinaryTreeNode<int> *root,map<int,pair<int,int>> &record,int dist,int depth){
    if(!root) return;
    auto check = record.find(dist);
    if(check==record.end() || depth>=record[dist].first){
        record[dist] = {depth,root->data};
    }
    preorder(root->left,record,dist-1,depth+1);
    preorder(root->right,record,dist+1,depth+1);

}
vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    map<int,pair<int,int>> record;
    preorder(root,record,0,0);
    vector<int> output;
    for(auto it:record){
        output.push_back(it.second.second);
    }
    return output;
}
