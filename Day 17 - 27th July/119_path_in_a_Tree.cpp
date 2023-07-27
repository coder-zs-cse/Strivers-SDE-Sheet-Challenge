#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/
int preorder(TreeNode<int> *root,int x,vector<int> &record){
	if(!root) return 0;
	record.push_back(root->data);
	if(x==root->data) return 1;
	if(preorder(root->left,x,record)) return 1;
	if(preorder(root->right,x,record)) return 1;
	record.pop_back();
	return 0;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> record;
	preorder(root,x,record);
	return record;
}
