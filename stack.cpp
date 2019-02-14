#include "stdafx.h"
#include "stack.h"
//2019.2.13--�Լ�ʵ��һ��ջ

template<typename T>
CStack<T>::CStack()
{
	top = NULL;
}

template<typename T>
CStack<T>::CStack(T val)
{
	top = new CNode;
	top->data = val;
	top->next = NULL;
}


template<typename T>
CStack<T>::~CStack()
{
	CNode *tmp_node = NULL;
	while (top != NULL)
	{
		tmp_node = top->next;
		delete top;
		//top�ͷ�֮��������ʣ�������ռ��������
		top = tmp_node;
	}
}











//init the stack
template<typename T>
void CStack<T>::init()
{
	if (empty())
	{
		top = new CNode();
		top->data = -1;
		top->next = NULL;
	}
}


template<typename T>
T CStack<T>::GetTopData()
{
	return top->data;
}



//push data into the stack
template<typename T>
void CStack<T>::Push(T val)
{
	CNode *new_node = new CNode;
	new_node->data = val;
	new_node->next = top;
	//topָ���µ�ջ��
	top = new_node;
}



//pop the top of stack,means size - 1
template<typename T>
void CStack<T>::Pop()
{
	//��ν����ջ������ʵ����ɾ��ջ���Ľڵ�
	CNode *node = top->next;
	delete top;
	//ջ��ָ����һ���ڵ�
	top = node;
}

//Get the size of stack
template<typename T>
int CStack<T>::Size()
{
	int size = 0;
	CNode *tmp_node = top;
	while (tmp_node != NULL)
	{
		size++;
		tmp_node = tmp_node->next;
	}
}


//if empty
template<typename T>
bool CStack<T>::empty()
{
	return top == NULL;
}