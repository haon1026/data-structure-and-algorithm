//ʱ�䣺2019��7��26��21:03:30
//C++�����ຯ��ʵ��

#include "list.h"

List::List()
{
	//������ͷ,��ͷ�����ʼ��
	InitListHead();
	//���ԼӲ����ͳ���
}

List::~List()
{
	//�ͷ�����
	freeList();
}

//������ͷ���
void List::InitListHead()
{
	//������ͷ���
	g_pHead = (Node *)malloc(sizeof(Node));   //�����ڴ�ռ�
	g_pHead->pNext = NULL;
	g_pEnd = g_pHead;    //β����ʱҪ��ͷ���ָ��ͬһ����ַ
}

//�����½��
Node *List::CreateNode(int val)
{
	Node *pNew = (Node *)malloc(sizeof(Node));
	//����ռ�ʧ��
	if (NULL == pNew)
	{
		return NULL;
	}
	//����ռ�ɹ�
	pNew->data = val;
	pNew->pNext = NULL;

	return pNew;
}

//����β���
void List::AddListTail(int val)
{
	Node *pNew = CreateNode(val);
	if (NULL == pNew)
	{
		cout <<"�����ڴ�ռ�ʧ�ܣ��ڴ治��\n";
		return;
	}
	//����
	g_pEnd->pNext = pNew;     //�����������޽�㣬����β������һ��������½��
	g_pEnd = pNew;
}

//����ͷ���
void List::AddListHead(int val)
{
	Node *pNew = CreateNode(val);
	if (NULL == pNew)
	{
		cout << "�����ڴ�ռ�ʧ�ܣ��ڴ治��\n";
		return;
	}
	pNew->pNext = g_pHead->pNext;     //�����������޽�㣬�����½�����һ������ǿ�ͷ������һ�����
	g_pHead->pNext = pNew;

	if (g_pEnd == g_pHead)       //������ǰ����Ϊ�գ���ʱ��ͷ����β�����ָ��ͬһ���ڴ�ռ䣬��Ӻ�β���Ҫ����
	{
		g_pEnd = pNew;
	}

}

//ָ��λ�����
void List::AddListRand(int index, int val)
{
	Node *pTemp = FindNode(index);   //Ҳ�������ж��Ƿ�Ϊ���ڲ���

	if (NULL == pTemp)
	{
		cout << "���޴˽�㣬�޷����!\n";
		return;
	}

	Node *pNew = CreateNode(val);
	if (NULL == pNew)
	{
		cout << "�����ڴ�ռ�ʧ�ܣ��ڴ治��\n";
		return;
	}
	//����ֱ��if�ж��Ƿ�pTemp��β��㣬�ǵĻ�����β��ӣ����ǵĻ��ٽ��в���
	pNew->pNext = pTemp->pNext;
	pTemp->pNext = pNew;

	if (pTemp == g_pEnd)    //���ָ����λ����β�����β�����Ҫָ���½��
	{
		g_pEnd = pNew;
	}
}

//����ָ����㣬�����ؽ���ַ
Node *List::FindNode(int val)
{
	if (NULL == g_pHead->pNext)
	{
		cout << "����Ϊ�գ��޷�����";
		return NULL;
	}

	Node *pTemp = g_pHead->pNext;
	while (pTemp != NULL)
	{
		if (val == pTemp->data)
		{
			//�ҵ���
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}
	//û�ҵ�
	return NULL;
}

//�����������
void List::ListTraversal()
{
	if (NULL == g_pHead->pNext)
	{
		cout << "����Ϊ��\n";
		return;
	}

	Node *pTemp = g_pHead->pNext;
	while (pTemp != NULL)
	{
		cout << pTemp->data << "  ";
		pTemp = pTemp->pNext;
	}
	cout << "\n";
}

//ɾ��ͷ��㣨��һ����Ч��㣩
void List::DeleteListHead()
{
	if (NULL == g_pHead->pNext)
	{
		cout << "����Ϊ�գ��޷�����ɾ����\n";
		return;
	}
	//����Ϊ��
	Node *pTemp = g_pHead->pNext;
	g_pHead->pNext = pTemp->pNext;

	if (pTemp == g_pEnd)   //���������ֻʣһ����Ч��㣬��������β��㣬ɾ����β���Ҫ����ָ���ͷ���ָ��Ŀռ䣻
	{
		g_pEnd = g_pHead;
	}
	free(pTemp);
}

//ɾ��β���
void List::DeleteListTail()
{
	if (NULL == g_pHead->pNext)
	{
		cout << "����Ϊ�գ��޷�����ɾ����\n";
		return;
	}

	if (g_pHead->pNext == g_pEnd)    //���ֻ��һ����Ч��㣬����ڵ����β��㣬ɾ����β���Ҫ����ָ���ͷ���ָ��Ŀռ�
	{
		g_pHead->pNext = NULL;
		free(g_pEnd);
		g_pEnd = g_pHead;
	}
	else
	{
		//��β����ǰһ�����
		//д��1
		Node *pTemp = g_pHead->pNext;
		while (pTemp->pNext != g_pEnd)   //�����ж����㣬��Ϊβ����ڵ�һ����Ч��������Ѿ����ǹ������Կ���ֱ�Ӵӵڶ�����Ч��㿪ʼ��
		{
			pTemp = pTemp->pNext;
		}
		free(g_pEnd);
		pTemp->pNext = NULL;
		g_pEnd = pTemp;

		//д��2
		/*Node *pTemp = g_pHead->pNext;
		while (pTemp != NULL)
		{
		if (pTemp->pNext == g_pEnd)
		{
		break;
		}
		pTemp = pTemp->pNext;
		}
		free(g_pEnd);
		pTemp->pNext = NULL;
		g_pEnd = pTemp;*/
	}
}

//ɾ��ָ�����
void List::DeleteListRand(int val)
{
	if (NULL == g_pHead->pNext)
	{
		cout << "����Ϊ�գ��޷�����ɾ����\n";
		return;
	}

	//û���ҵ�ָ�����
	Node *pTemp = FindNode(val);
	if (NULL == pTemp)
	{
		cout << "���޴˽�㣬����ɾ��!\n";
		return;
	}

	if (pTemp == g_pEnd)   //ָ�������β���
	{
		DeleteListTail();
	}
	else           //ָ����㲻��β���
	{
		Node *pt = g_pHead;
		while (pt->pNext != pTemp)     //�ӵ�һ����Ч��㿪ʼ����
		{
			pt = pt->pNext;
		}
		pt->pNext = pTemp->pNext;
		free(pTemp);
	}
}

//�ͷ�����
void List::freeList()
{
	Node *pTemp = g_pHead; // g_pHead->pNext /  g_pHead    //����ǳ������ʩ��������Ҫ�ѿ�ͷ���Ҳɾ��������Ǵ���ɾ���󻹿��Լ�����ӾͲ���ɾ��
	while (pTemp != NULL)
	{
		Node *pT = pTemp;
		pTemp = pTemp->pNext;
		free(pT);
	}
	g_pEnd = NULL;
	g_pHead = NULL;
}
