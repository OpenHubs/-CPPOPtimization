// RefOptimization.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "stack.h"
#include "stack.cpp"
#include "RBTree.h"
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include <stack>
#include <queue>
#include <deque>
#include <list>
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

	//测试红黑树
#if 0
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


	//测试二叉树
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

	cout << "tree depth: ..." << endl;
	int depth = b_tree.GetTreeDepth();
	cout << depth << endl;
#endif



	//STL标准模板库的测试
#if 0
//测试STL标准库中的栈(stack)(FILO)
	cout << "-----------stack------------" << endl;
	stack<double> p_stack_list;
	for (auto i = 0;i < 10;i++)
	{
		p_stack_list.push((double)i);
	}
	for (auto m = 0;m < p_stack_list.size();m++)
	{
		cout << p_stack_list.top() << endl;
		p_stack_list.pop();
		m--;
		if (p_stack_list.empty())
		{
			break;
		}
	}


//测试STL标准库中的队列(queue)
	cout << "-------------queue------------" << endl;
	queue<double> p_queue_list;
	for (auto i = 0;i < 6;i++)
	{
		p_queue_list.push((double)i);
	}
	cout << "---------------front of queue------------" << endl;
	for (auto m = 0; m < p_queue_list.size(); m++)
	{
		cout << p_queue_list.front() << endl;
		p_queue_list.pop();
		m--;
	}
	cout << "----------------back of queue----------------" << endl;
	for (auto i = 0; i < 6; i++)
	{
		p_queue_list.emplace((double)i);
	}
	for (auto m = 0;m < p_queue_list.size();m++)
	{
		cout << p_queue_list.back() << endl;
	}
	for (auto m = 0; m < p_queue_list.size(); m++)
	{
		cout << p_queue_list.front() << endl;
		p_queue_list.pop();
		m--;
	}

//测试STL标准库中的双端队列(dequeue)
	cout << "----------dequeue-------------" << endl;
	deque<double> p_deque_list;
	for (auto m = 0;m < 6;m++)
	{
		p_deque_list.emplace_front((double)m);
	}

	for (auto i = 0;i < 6;i++)
	{
		cout << p_deque_list.at(i) << endl;
	}
	cout << "==========" << endl;
	p_deque_list.assign(6,7);
	for (auto iter = p_deque_list.begin();iter != p_deque_list.end();iter++)
	{
		cout << *iter << endl;
	}

//测试STL标准模板库之LIST容器，这个容器不支持随机访问，只支持删除与插入,因为它是链表
	cout << "----list----" << endl;
	list<int> p_list;
	p_list.emplace_front(1);
	p_list.emplace_front(2);
	p_list.emplace_front(3);
	p_list.emplace_back(5);
	p_list.emplace_back(6);

	for (auto iter = p_list.begin();iter != p_list.end();iter++)
	{
		//3,2,1,5,6
		cout << *iter << endl;
	}
    //从LIST中间删除一个元素
	p_list.remove(5);
	cout << "---" << endl;
	for (auto iter = p_list.begin(); iter != p_list.end(); iter++)
	{
		//3,2,1,6
		cout << *iter << endl;
	}
	//在LIST中间插入一个元素(指定位置需要用到迭代器，其实比较麻烦)
	cout << "---" << endl;
	auto iter = p_list.begin();
	iter++;
	p_list.insert(iter, 10);

	for (auto iter = p_list.begin();iter != p_list.end();iter++)
	{
		cout << *iter << endl;
	}

#endif




#if 1
     //测试自己定义的数据结构--栈
	CStack<double> my_stack;

	my_stack.Push(1);
	my_stack.Push(2);
	my_stack.Push(3);
	my_stack.Push(4);
	//the top is 4
	cout << my_stack.GetTopData() << endl;
	//pop the top
	my_stack.Pop();
	//the top is 3
	cout << my_stack.GetTopData() << endl;
	my_stack.Pop();
	//the top is 2
	cout << my_stack.GetTopData() << endl;
	my_stack.Pop();
	//the top is 1
	cout << my_stack.GetTopData() << endl;
	my_stack.Pop();

#endif














































	Sleep(10000);
    return 0;
}

