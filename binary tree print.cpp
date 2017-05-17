// nowcode.cpp : 定义控制台应用程序的入口点。
//有一棵二叉树，请设计一个算法，按照层次打印这棵二叉树。

//给定二叉树的根结点root，请返回打印结果，结果按照每一层一个数组进行储存，所有数组的顺序按照层数从上往下，且每一层的数组内元素按照从左往右排列。保证结点数小于等于500。

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class TreePrinter {
public:
    vector<vector<int> > printTree(TreeNode* root) {
        vector<vector<int> > res;
        vector<int> temp;
       
        TreeNode *last=root,*nlast=root,*node=nullptr;
        deque<TreeNode *> q;
        q.push_back(root);
        while(!q.empty())
            {
            node=q.front();
            temp.push_back(node->val);
            q.pop_front();
            if(node->left!=nullptr)
                {
                q.push_back(node->left);
                
                nlast=node->left;
                
            }
            if(node->right!=nullptr)
                {
                q.push_back(node->right);
                
                nlast=node->right;
            }
            if(node==last)
                {
                res.push_back(temp);
                temp.clear();
                last=nlast;
            }
        }
        return res;
    }
};
int main()
{
	return 0;
}
