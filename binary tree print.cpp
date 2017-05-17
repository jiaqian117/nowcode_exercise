// nowcode.cpp : �������̨Ӧ�ó������ڵ㡣
//��һ�ö������������һ���㷨�����ղ�δ�ӡ��ö�������

//�����������ĸ����root���뷵�ش�ӡ������������ÿһ��һ��������д��棬���������˳���ղ����������£���ÿһ���������Ԫ�ذ��մ����������С���֤�����С�ڵ���500��

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
