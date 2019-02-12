// RefOptimization.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "RBTree.h"
#include "BinaryTree.h"
#include "BinaryTree.cpp"
using namespace std;

int g_constructorCount = 0;
int g_copyConstructCount = 0;
int g_desstructCount = 0;

struct A
{
	A()
	{
		cout << "contrcutor: " << ++g_constructorCount << endl;
    }

	A(const A& a)
	{
		cout << "copy construct: " << ++g_copyConstructCount << endl;
	}

	~A()
	{
		cout << "" << ++g_desstructCount << endl;
	}
};

A GetA()
{
	return A();
}


int main()
{
	//A a = GetA();
	//A&& a = GetA();

#if 1
	//
	int a[] = { 10, 40, 30, 60, 90, 70, 20, 50, 80 };
	int check_insert = 0;    // "插入"动作的检测开关(0，关闭；1，打开)
	int check_remove = 0;    // "删除"动作的检测开关(0，关闭；1，打开)
	int i;
	int ilen = (sizeof(a)) / (sizeof(a[0]));
	RBTree<int>* tree = new RBTree<int>();

	cout << "== 原始数据: ";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	for (i = 0; i < ilen; i++)
	{
		tree->insert(a[i]);
		// 设置check_insert=1,测试"添加函数"
		if (check_insert)
		{
			cout << "== 添加节点: " << a[i] << endl;
			cout << "== 树的详细信息: " << endl;
			tree->print();
			cout << endl;
		}
	}

	cout << "== 前序遍历: ";
	tree->preOrder();

	cout << "\n== 中序遍历: ";
	tree->inOrder();

	cout << "\n== 后序遍历: ";
	tree->postOrder();
	cout << endl;

	cout << "== 最小值: " << tree->minimum() << endl;
	cout << "== 最大值: " << tree->maximum() << endl;
	cout << "== 树的详细信息: " << endl;
	tree->print();

	// 设置check_remove=1,测试"删除函数"
	if (check_remove)
	{
		for (i = 0; i < ilen; i++)
		{
			tree->remove(a[i]);

			cout << "== 删除节点: " << a[i] << endl;
			cout << "== 树的详细信息: " << endl;
			tree->print();
			cout << endl;
		}
	}

	// 销毁红黑树
	tree->destroy();
#endif

#if 0
	//二叉树的操作过程
	int root = 10;
	int my_array[] = {2,1,3,5,7,9,11,13,15,17};
	BinaryTree<int> b_tree(root);
	b_tree.Insert(my_array[0]);
	b_tree.Insert(my_array[1]);
	b_tree.Insert(my_array[2]);
	b_tree.Insert(my_array[3]);
	b_tree.Insert(my_array[4]);
	b_tree.Insert(my_array[5]);
	b_tree.Insert(my_array[6]);
	b_tree.Insert(my_array[7]);
	b_tree.Insert(my_array[8]);
	b_tree.Insert(my_array[9]);

	b_tree.PreOrder();
	cout << "\n" << endl;
	b_tree.InOrder();
	cout << "\n" << endl;
	b_tree.PostOrder();

	cout << "\n After delete 17..." << endl;
	b_tree.Remove(17);
	b_tree.PreOrder();
	cout << "\n" << endl;
	b_tree.InOrder();
	cout << "\n" << endl;
	b_tree.PostOrder();

	cout << "\n After delete 2... ..." << endl;
	b_tree.Remove(2);
	cout << "\n ... ..." << endl;
	b_tree.PreOrder();
#endif

	Sleep(10000);
    return 0;
}

