#pragma once
//������ջ���Ƕ������Ƚṹ��ʵ�ֵ�ʱ��Ӧ���ȶ������Ľڵ㣬��Ϊ�����϶����������


template<typename T>
class CStack
{
public:
	CStack();
	~CStack();
	CStack(T val);
	//init the stack
	void init();
	//push data into the stack
	void Push(T val);
	//Pop element
	void Pop();
	//Get the data of top node
	T GetTopData();

	//Get the size of stack
	int Size();
	//if empty
	bool empty();




public:
	class CNode
	{
	public:
		CNode()
		{
			next = NULL;
		}
		CNode(T val)
		{
			data = val;
		}
		~CNode()
		{

		}
		T data;
		CNode *next;
	};
	CNode *top;
};