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



//获得节点的父节点
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
	//先左子树
	GetParentNode(bNode, subTree->left_node);
	//后右子树
	GetParentNode(bNode, subTree->right_node);
}








//克隆一棵树（二叉树）
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


//插入节点(指定节点的KEY值)
//将KEY值插入到指定的NODE下面
//如果KEY值小于当前节点的KEY值，那么插入到节点的左子树
//如果KEY值大于当期节点的KEY值，那么插入到节点的右子树
//困惑的是如何把参数中的KEY值插入到子树中的节点里。
template<typename T>
void BinaryTree<T>::insert(const T& theElement,BinaryNode* &bNode)
{
	//如果当前树是空的
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
		//重复的数据不会插入进来
	}
}


//删除二叉树的节点(给定这个节点的KEY值)
//这个删除方法有点拗口，分为几种情况去处理
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
			//找到了指定KEY值的节点,且这个节点的左右子节点非空
			//此时如果要删除节点，需要从其右子树中找到最小的节点来填充到当前节点位置。
			tmp_node = findMin(bNode->right_node);
			bNode->element = tmp_node->element;
			remove(bNode->element, bNode->right_node);
		}
		else
		{
			tmp_node = bNode;
			//如果左右两个节点都是空的，直接删除当前节点
			if (!bNode->right_node && !bNode->left_node)
			{
				delete bNode; bNode = NULL;
				return;
			}
			//如果右节点为非空
			if (bNode->right_node != NULL)
			{
				bNode = bNode->right_node;
			}
			//如果左边的节点为非空
            if (bNode->left_node != NULL)
            {
				bNode = bNode->left_node;
            }
			delete tmp_node; tmp_node = NULL;
		}
	}
}



//清空整棵树(注意形参的写法，必须加上引用)
//清空的具体方法就是逐个删除节点
//本函数使用的方法：
//给定任意一个节点
//然后依次删除此节点的左右子树上的节点
//程序非常简单，就是递归方法。
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



//查找最小和最大的节点
//查找一颗树或者是一棵子树的最小节点或最大节点
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

//请特别注意typename和class的区别：一般情况下，二者是通用的
//但是当泛型T是一个类时，

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







//前中后-遍历
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