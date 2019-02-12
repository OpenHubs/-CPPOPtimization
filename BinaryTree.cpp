#include "stdafx.h"
#include "BinaryTree.h"


template<typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& bt)
{
	if (bt->root)
	{
		root = bt->root;
	}
	else {
		root = nullptr;
	}
}

template<typename T>
BinaryTree<T>::BinaryTree(const T element)
{
	root = new BinaryNode(element);
}


template<typename T>
BinaryTree<T>::~BinaryTree()
{
	MakeEmpty();
}




template<typename T>
void BinaryTree<T>::Insert(const T& theElement)
{
	insert(theElement, root);
}


template<typename T>
void BinaryTree<T>::Remove(const T& theElement)
{
	remove(theElement, root);
}


template<typename T>
void BinaryTree<T>::MakeEmpty()
{
	makeEmpty(root);
}


template<typename T>
bool BinaryTree<T>::IsFind(const T& theElement)
{
	if (isFind(theElement,root))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void BinaryTree<T>::PreOrder()
{
	preOrder(root);
}

template<typename T>
void BinaryTree<T>::InOrder()
{
	inOrder(root);
}

template<typename T>
void BinaryTree<T>::PostOrder()
{
	postOrder(root);
}



//��ýڵ�ĸ��ڵ�
template<typename T>
typename BinaryTree<T>::BinaryNode* BinaryTree<T>::GetParentNode(BinaryNode *bNode, BinaryNode* &subTree)
{
	if (bNode == root)
	{
		return NULL;
	}
	if (bNode == subTree->left_node || bNode == subTree->right_node)
	{
		return subTree;
	}
	//��������
	GetParentNode(bNode, subTree->left_node);
	//��������
	GetParentNode(bNode, subTree->right_node);
}








//��¡һ��������������
template<typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::clone(const BinaryNode *root)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	else
	{
		return new BinaryNode(root->element,root->left_node,root->right_node);
	}
}


//����ڵ�(ָ���ڵ��KEYֵ)
//��KEYֵ���뵽ָ����NODE����
//���KEYֵС�ڵ�ǰ�ڵ��KEYֵ����ô���뵽�ڵ��������
//���KEYֵ���ڵ��ڽڵ��KEYֵ����ô���뵽�ڵ��������
//���������ΰѲ����е�KEYֵ���뵽�����еĽڵ��
template<typename T>
void BinaryTree<T>::insert(const T& theElement,BinaryNode* &bNode)
{
	//�����ǰ���ǿյ�
	if (bNode == NULL)
	{
		bNode = new BinaryNode(theElement);
	}
	else if(theElement < bNode->element)
	{
		insert(theElement, bNode->left_node);
	}
	else if (theElement > bNode->element)
	{
		insert(theElement, bNode->right_node);
	}
	else
	{
		//�ظ������ݲ���������
	}
}


//ɾ���������Ľڵ�(��������ڵ��KEYֵ)
//���ɾ�������е��ֿڣ���Ϊ�������ȥ����
//1.
//2.
//3.
template<typename T>
void BinaryTree<T>::remove(const T& theElement, BinaryNode* &bNode)
{
	BinaryNode *tmp_node;
	if (nullptr == bNode)
	{
		return;
	}
	else
	{
		if (theElement < bNode->element)
		{
			remove(theElement, bNode->left_node);//hsu
		}
		else if (theElement > bNode->element)
		{
			remove(theElement, bNode->right_node);
		}
		else if (nullptr != bNode->left_node && nullptr != bNode->right_node)
		{
			//theElement == bNode->element
			//�ҵ���ָ��KEYֵ�Ľڵ�,������ڵ�������ӽڵ�ǿ�
			//��ʱ���Ҫɾ���ڵ㣬��Ҫ�������������ҵ���С�Ľڵ�����䵽��ǰ�ڵ�λ�á�
			tmp_node = findMin(bNode->right_node);
			bNode->element = tmp_node->element;
			remove(bNode->element, bNode->right_node);
		}
		else
		{
			tmp_node = bNode;
			//������������ڵ㶼�ǿյģ�ֱ��ɾ����ǰ�ڵ�
			if (!bNode->right_node && !bNode->left_node)
			{
				delete bNode; bNode = NULL;
				return;
			}
			//����ҽڵ�Ϊ�ǿ�
			if (bNode->right_node != NULL)
			{
				bNode = bNode->right_node;
			}
			//�����ߵĽڵ�Ϊ�ǿ�
            if (bNode->left_node != NULL)
            {
				bNode = bNode->left_node;
            }
			delete tmp_node; tmp_node = NULL;
		}
	}
}



//���������(ע���βε�д���������������)
//��յľ��巽���������ɾ���ڵ�
//������ʹ�õķ�����
//��������һ���ڵ�
//Ȼ������ɾ���˽ڵ�����������ϵĽڵ�
//����ǳ��򵥣����ǵݹ鷽����
template<typename T>
void BinaryTree<T>::makeEmpty(BinaryNode* &t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left_node);
		makeEmpty(t->right_node);
		cout << "deleted node: " << t->element << std::endl;
		delete t;
	}
	t = nullptr;
}




//Find the node with given key value
template<typename T>
bool BinaryTree<T>::isFind(const T &theElement, BinaryNode* t)const
{
    if (t == nullptr)
    {
		return false;
    }
	if (theElement < t->element)
	{
		return isFind(theElement, t->left_node);
	}
	else if (theElement > t->element)
	{
		return isFind(theElement,t->right_node);
	}
	else
	{
		return true;
	}
}



//������С�����Ľڵ�
//����һ����������һ����������С�ڵ�����ڵ�
template<typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::findMin(BinaryNode * bNode)const
{
	if (bNode != NULL)
	{
		while (bNode->left_node != nullptr)
		{
			bNode = bNode->left_node;
		}
	}

	return bNode;
}

//���ر�ע��typename��class������һ������£�������ͨ�õ�
//���ǵ�����T��һ����ʱ��

template<typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::findMax(BinaryNode * bNode)const
{
	if (bNode != NULL)
	{
		while (bNode->right_node)
		{
			bNode = bNode->right_node;
		}
	}
	return tmp_node;
}







//ǰ�к�-����
template<typename T>
void BinaryTree<T>::preOrder(BinaryNode* bNode)const
{
	//DLR
	if (bNode != NULL)
	{
		cout << " node: " << bNode->element;
		preOrder(bNode->left_node);
		preOrder(bNode->right_node);
	}
}

template<typename T>
void BinaryTree<T>::inOrder(BinaryNode* bNode)const
{
	//LDR
	if (bNode != NULL)
	{
		inOrder(bNode->left_node);
		cout << " node: " << bNode->element;
		inOrder(bNode->right_node);
	}
}

template<typename T>
void BinaryTree<T>::postOrder(BinaryNode* bNode)const
{
	//LRD
	if (bNode != NULL)
	{
		postOrder(bNode->left_node);
		postOrder(bNode->right_node);
		cout << " node: " << bNode->element;
	}
}



template<typename T>
int BinaryTree<T>::GetTreeDepth(BinaryNode* bNode)
{

}