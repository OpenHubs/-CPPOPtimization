#pragma once
#include <iostream>
//const ����Ӧ���ڳ�Ա�����У����糣����
//�����ǽ�ֹ�ڳ������ڲ������޸ĳ�Ա������
//�����ڳ������ڲ�Ҳ������ʹ�÷ǳ�����
//����CONST�����кܶ��÷��������β��б�����ʹ��
//const,���о��Ƿ���ֵʹ��CONST�����Ǻ����ķ���ֵ
//ǰ������CONSTû��ʵ�����塣

template<typename T>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const BinaryTree& bt);
	BinaryTree(const T element);
	~BinaryTree();//�������������б�Ϊ��
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
		//�ڵ���3����ʽ�Ĺ��캯��
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

	BinaryNode *root;//���ڵ�
	//��¡������
	BinaryNode *clone(const BinaryNode *root);
	//���룬ɾ������ղ���
	void insert(const T& theElement,BinaryNode* &bNode);
	void remove(const T& theElement,BinaryNode* &bNode);
	void makeEmpty(BinaryNode* &t);
	//����ָ���Ľڵ㣬���ݽڵ��KEYֵ
	bool isFind(const T &theElement, BinaryNode* t)const;

	//������С�����Ľڵ�
	BinaryNode * findMin(BinaryNode * bNode)const;
	BinaryNode * findMax(BinaryNode * bNode)const;

	//ǰ�к�-����
	void preOrder(BinaryNode* bNode)const;
	void inOrder(BinaryNode* bNode)const;
	void postOrder(BinaryNode* bNode)const;

	//
	//��ýڵ�ĸ��ڵ�
	BinaryNode * GetParentNode(BinaryNode *bNode, BinaryNode* &subTree);

	//���������ȣ�����������ȣ�����������ȣ�
	int GetTreeDepth(BinaryNode* bNode);
};

















