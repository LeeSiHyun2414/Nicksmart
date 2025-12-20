#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct tTreeNode {
	void* data;
	struct tTreeNode* left, * right;
}TreeNode;
typedef struct {
	int(*compare)(void* a, void* b);
	int count;
	TreeNode* root;
}Tree;
Tree* CreateTree(int(*compare)(void* a, void* b))
{
	Tree* pTree = (Tree*)malloc(sizeof(Tree));
	if (pTree == NULL)
		return NULL;
	pTree->compare = compare;
	pTree->count = 0;
	pTree->root = NULL;
	return pTree;
}
TreeNode* Insert_pri(Tree* pTree, TreeNode* root, TreeNode* news);
TreeNode* Delete_pri(Tree* pTree, TreeNode* root, void* data, int* success);
TreeNode* Search(Tree* pTree, TreeNode* root, void* data)
{
	if (pTree == NULL)
		return NULL;
	if (pTree->compare(root->data, data) > 0)
		return Search(pTree, root->left, data);
	else if (pTree->compare(root->data, data) < 0)
		return Search(pTree, root->right, data);
	else
		return root;
}
void Insert(Tree* pTree, void* data)
{
	TreeNode* pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (pNewNode == NULL)
		return;
	pNewNode->left = pNewNode->right = NULL;
	pNewNode->data = data;
	if (pTree->root == NULL)
		pTree->root = pNewNode;
	else
		Insert_pri(pTree, pTree->root, pNewNode);
	pTree->count++;
}
TreeNode* Insert_pri(Tree* pTree, TreeNode* root, TreeNode* news)
{
	if (pTree == NULL)
		return NULL;
	if (root == NULL)
		return news;
	if (pTree->compare(root->data, news->data) > 0)
		root->left = Insert_pri(pTree, root->left, news);
	else
		root->right = Insert_pri(pTree, root->right, news);
	return root;
}
void Delete(Tree* pTree, void* data)
{
	int success = 0;
	if (pTree == NULL)
		return;
	Delete_pri(pTree, pTree->root, data, &success);
}
TreeNode* Delete_pri(Tree* pTree, TreeNode* root, void* data, int* success)
{
	TreeNode* pdel;
	if (pTree == NULL || root == NULL)
	{
		*success = 0;
		return NULL;
	}
	if (pTree->compare(root->data, data) > 0)
		root->left = Delete_pri(pTree, root->left, data, success);
	else if (pTree->compare(root->data, data) < 0)
		root->right = Delete_pri(pTree, root->right, data, success);
	else
	{
		*success = 1;
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		else if (root->right == NULL)
		{
			pdel = root->left;
			free(root);
			return pdel;
		}
		else if (root->left == NULL)
		{
			pdel = root->right;
			free(root);
			return pdel;
		}
		else
		{
			pdel = root->left;
			while (pdel)
				pdel = pdel->right;
			root->data = pdel->data;
			root->left = Delete_pri(pTree, root->left, data, success);
		}
	}
}
void PrintBST(TreeNode*root,void*process(void*data))
{
	if (root == NULL)
		return;
	PrintBST(root->left,process);
	(*process)(root->data);
	PrintBST(root->right, process);
}
void DestroyTree(TreeNode* root)
{
	if (root == NULL)
		return;
	if (root->left)
		DestroyTree(root->left);
	if (root->right)
		DestroyTree(root->right);
	free(root);
}
