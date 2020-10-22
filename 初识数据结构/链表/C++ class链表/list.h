//ʱ�䣺2019��7��26��20:46:48
//C++����ͷ�ļ�

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

//���ṹ��
struct Node
{
	int data;
	struct Node *pNext;
};


class List
{
public:
	List();
	~List();

	//����β���
	void AddListTail(int val);

	//����ͷ���
	void AddListHead(int val);

	//ָ��λ�����
	void AddListRand(int index, int val);

	//����ָ��λ��
	struct Node *FindNode(int val);

	//�����������
	void ListTraversal();

	//ɾ��ָ�����
	void DeleteListRand(int val);

private:
	//ͷβָ�붨��
	Node *g_pHead = NULL;   //C++ struct�ɲ�д
	Node *g_pEnd = NULL;

private:
	//������ͷ,��ͷ�����ʼ��
	void InitListHead();

	//�����½��
	struct Node *CreateNode(int val);

	//ɾ��ͷ��㣨��һ����Ч��㣩
	void DeleteListHead();

	//ɾ��β���
	void DeleteListTail();

	//�ͷ�����
	void freeList();
};


