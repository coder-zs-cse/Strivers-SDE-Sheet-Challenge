#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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
void preorder(TreeNode<int> *root,map<int,pair<int,int>> &record,int dist,int depth){
    if(!root) return;
    auto check = record.find(dist);
    if(check==record.end() || depth<record[dist].first){
        record[dist] = {depth,root->val};
    }
    preorder(root->left,record,dist-1,depth+1);
    preorder(root->right,record,dist+1,depth+1);

}
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    map<int,pair<int,int>> record;
    preorder(root,record,0,0);
    vector<int> output;
    for(auto it:record){
        output.push_back(it.second.second);
    }
    return output;
}