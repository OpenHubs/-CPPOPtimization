// RefOptimization.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int check_insert = 0;    // "����"�����ļ�⿪��(0���رգ�1����)
	int check_remove = 0;    // "ɾ��"�����ļ�⿪��(0���رգ�1����)
	int i;
	int ilen = (sizeof(a)) / (sizeof(a[0]));
	RBTree<int>* tree = new RBTree<int>();

	cout << "== ԭʼ����: ";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	for (i = 0; i < ilen; i++)
	{
		tree->insert(a[i]);
		// ����check_insert=1,����"��Ӻ���"
		if (check_insert)
		{
			cout << "== ��ӽڵ�: " << a[i] << endl;
			cout << "== ������ϸ��Ϣ: " << endl;
			tree->print();
			cout << endl;
		}
	}

	cout << "== ǰ�����: ";
	tree->preOrder();

	cout << "\n== �������: ";
	tree->inOrder();

	cout << "\n== �������: ";
	tree->postOrder();
	cout << endl;

	cout << "== ��Сֵ: " << tree->minimum() << endl;
	cout << "== ���ֵ: " << tree->maximum() << endl;
	cout << "== ������ϸ��Ϣ: " << endl;
	tree->print();

	// ����check_remove=1,����"ɾ������"
	if (check_remove)
	{
		for (i = 0; i < ilen; i++)
		{
			tree->remove(a[i]);

			cout << "== ɾ���ڵ�: " << a[i] << endl;
			cout << "== ������ϸ��Ϣ: " << endl;
			tree->print();
			cout << endl;
		}
	}

	// ���ٺ����
	tree->destroy();
#endif

#if 0
	//�������Ĳ�������
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

