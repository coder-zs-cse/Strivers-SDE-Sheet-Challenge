#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> output;
    map<int,vector<int>> record;
    queue<pair<int,TreeNode<int>*>> q;
    q.push(make_pair(0,root));
    while(!q.empty()){
        pair<int,TreeNode<int>*> current = q.front();
        q.pop();
        record[current.first].push_back(current.second->data);
        if(current.second->left) q.push(make_pair(current.first-1,current.second->left));
        if(current.second->right) q.push(make_pair(current.first+1,current.second->right));

    }
    for(auto it:record){
        for(auto num:it.second)  output.push_back(num);
    }

    return output;
}