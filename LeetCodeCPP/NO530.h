#pragma once
#include<stdio.h>
#include<math.h>
#include <climits>
  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution530 {
public:
    int getMinimumDifference(TreeNode* root) {
		int Left=INT_MAX,right=INT_MAX,differL=INT_MAX,differR=INT_MAX;
		TreeNode* LeftNode=NULL;TreeNode* RightNode=NULL;
		TreeNode* OldLeftNode=NULL;TreeNode* OldRightNode=NULL;
		if(root->left!=NULL)
		{ 
		LeftNode=root->left;
		OldLeftNode=LeftNode;
		while (LeftNode!=NULL)
		{   OldLeftNode=LeftNode;
			LeftNode=LeftNode->right;
		}
		Left=getMinimumDifference(root->left);
	   differL=abs(root->val-OldLeftNode->val);
	   differL=differL>Left?Left:differL;
		}
		if(root->right!=NULL)
		{
		RightNode=root->right;
		OldRightNode=RightNode;
		while (RightNode!=NULL)
		{OldRightNode=RightNode;
			RightNode=RightNode->left;
		}
		 right=getMinimumDifference(root->right);
		 differR=abs(root->val-OldRightNode->val);
		 differR=differR>right?right:differR;
		}
		return differR>differL?differL:differR;
    }
    
};