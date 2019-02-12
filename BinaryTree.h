#pragma once
#include <iostream>
//const 经常应用在成员函数中，例如常函数
//作用是禁止在常函数内部随意修改成员变量，
//另外在常函数内部也不允许使用非常函数
//关于CONST，还有很多用法：例如形参列表里面使用
//const,还有就是返回值使用CONST，但是函数的返回值
//前面修饰CONST没有实际意义。

template<typename T>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const BinaryTree& bt);
	BinaryTree(const T element);
	~BinaryTree();//析构函数参数列表为空
	void Insert(const T& theElement);
	void Remove(const T& theElement);
	void MakeEmpty();
	bool IsFind(const T& theElement);
	void PreOrder();
	void InOrder();
	void PostOrder();



private:
	struct BinaryNode
	{
		T element;
		BinaryNode * left_node;
		BinaryNode * right_node;
		//节点有3种形式的构造函数
		BinaryNode(const T ele, BinaryNode *leftNode, BinaryNode* rightNode) :
			element(ele), left_node(leftNode), right_node(rightNode)
		{

		}

		BinaryNode(const BinaryNode* bn)
			:element(bn->element), left_node(bn->left_node), right_node(bn->right_node)
		{

		}

		BinaryNode(const T& ele) :
			element(ele), left_node(NULL), right_node(NULL)
		{

		}
	};

	BinaryNode *root;//根节点
	//克隆二叉树
	BinaryNode *clone(const BinaryNode *root);
	//插入，删除，清空操作
	void insert(const T& theElement,BinaryNode* &bNode);
	void remove(const T& theElement,BinaryNode* &bNode);
	void makeEmpty(BinaryNode* &t);
	//查找指定的节点，根据节点的KEY值
	bool isFind(const T &theElement, BinaryNode* t)const;

	//查找最小和最大的节点
	BinaryNode * findMin(BinaryNode * bNode)const;
	BinaryNode * findMax(BinaryNode * bNode)const;

	//前中后-遍历
	void preOrder(BinaryNode* bNode)const;
	void inOrder(BinaryNode* bNode)const;
	void postOrder(BinaryNode* bNode)const;

	//
	//获得节点的父节点
	BinaryNode * GetParentNode(BinaryNode *bNode, BinaryNode* &subTree);

	//获得树的深度（左子树的深度，右子树的深度）
	int GetTreeDepth(BinaryNode* bNode);
};

















