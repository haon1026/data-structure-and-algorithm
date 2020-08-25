//ʱ�䣺2019��7��26��10:22:22
//�޿�ͷ����

#include <stdio.h>
#include <stdlib.h>

//������ṹ��
struct Node
{
	int data;
	struct Node *pNext;
};

//����ȫ�ֱ�����ͷβָ��
struct Node *g_pHead = NULL;
struct Node *g_pEnd = NULL;

//�������������������һ�����ݣ�β���
void AddNodeToListTail(int val);

//�������������������һ�����ݣ�ͷ���
void AddNodeToListHead(int val);

//��������
void ListTraversal();

//����ָ�����ݵĽ��
struct Node * findNodeFromList(int val);

//ָ�����ݺ������
void AddListRand(int index, int val);

//�������
void clearList();

//ͷɾ�����
void DeleteNodeFromListHead();

//βɾ�����
void DeleteNodeFromListTail();

//ɾ��ָ�����ݵĽ��
void deleteNodeFromList(int val);
/*
int main()
{
	AddNodeToListHead(1);
	AddNodeToListHead(2);
	AddNodeToListHead(3);
	AddNodeToListHead(4);
	AddNodeToListHead(5);
	AddNodeToListHead(6);
	AddNodeToListHead(7);
	ListTraversal();

	deleteNodeFromList(4);
	ListTraversal();
	AddNodeToListTail(12);
	AddListRand(1, 50);
	ListTraversal();
	clearList();
	system("pause");
	return 0;
}
*/
//β��ӽ��
void AddNodeToListTail(int val)
{
	//�����½��
	struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
	pNew->data = val;
	pNew->pNext = NULL;

	//����
	if (NULL == g_pHead)  //����Ϊ��
	{
		g_pHead = pNew;
		g_pEnd = pNew;
	}
	else   //����Ϊ��
	{
		g_pEnd->pNext = pNew;
		g_pEnd = pNew;
	}
	//g_pEnd = pNew; �ظ��˿�ͳһд������
}

//ͷ��ӽ��
void AddNodeToListHead(int val)
{
	//�����½��
	struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
	pNew->data = val;
	pNew->pNext = NULL;

	//����
	if (NULL == g_pHead)   //����Ϊ��
	{
		g_pHead = pNew;   
		g_pEnd = pNew;
	}
	else   //����Ϊ��
	{
		pNew->pNext = g_pHead;
		g_pHead = pNew;
	}
	//g_pHead = pNew;; �ظ��˿�ͳһд������
}

//��������
void ListTraversal()
{
	//������ʱ���
	struct Node *pTemp = g_pHead;
	//����
	while (pTemp != NULL)
	{
		printf("%d  ", pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}

//����ָ�����
struct Node * findNodeFromList(int val)
{
	//������ʱ���
	struct Node *pTemp = g_pHead;

	//����
	while (pTemp != NULL)
	{
		if (val == pTemp->data)
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}
	//û�ҵ�����NULL
	return NULL;
}

//ָ��λ�ò�����
void AddListRand(int index, int val)
{
	//����Ϊ��    
	if (NULL == g_pHead)
	{
		printf("����û�н��\n");
		return;
	}

	//���ҽ��
	struct Node *pTemp = findNodeFromList(index);    //�ҵ����Ҳ����������ܣ��Ҳ����Ļ���������Ϊ�յ����

	//��㲻����
	if (NULL == pTemp)
	{
		printf("û��ָ���ڵ�\n");
		return;
	}

	//������
	struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
	pNew->data = val;
	pNew->pNext = NULL;

	//***����Ҫ����ָ��λ���Ƿ�Ϊβ���***
	if (pTemp == g_pEnd)
	{
		g_pEnd->pNext = pNew;
		g_pEnd = pNew;
	}
	else
	{
		pNew->pNext = pTemp->pNext;
		pTemp->pNext = pNew;
	}
}

//�������
void clearList()
{
	struct Node *pTemp = g_pHead;
	while (g_pHead != NULL)
	{
		pTemp = g_pHead;
		g_pHead = g_pHead->pNext;
		free(pTemp);
	}
	//ͷβ���
	g_pEnd = NULL;
	g_pHead = NULL;
}

//ͷɾ�����
void DeleteNodeFromListHead()
{
	if (NULL == g_pHead)    //����Ϊ��
	{
		printf("����Ϊ��,����ʩ��\n");
		return;
	}
	else if (g_pHead == g_pEnd)   //ֻ��һ�����
	{
		free(g_pHead);
		g_pHead = NULL;
		g_pEnd = NULL;
	}
	else            //һ���������
	{
		struct Node *pTemp = g_pHead;
		g_pHead = g_pHead->pNext;
		free(pTemp);
	}
}

//βɾ�����
void DeleteNodeFromListTail()
{
	if (NULL == g_pHead)    //����Ϊ��
	{
		printf("����Ϊ��,����ʩ��\n");
		return;
	}
	else if (g_pHead == g_pEnd)   //ֻ��һ�����
	{
		free(g_pHead);
		g_pHead = NULL;
		g_pEnd = NULL;
	}
	else  //һ���������
	{
		struct Node *pTemp = g_pHead;
		while (pTemp->pNext != g_pEnd)   //����Ѱ��β����ǰһ�����
		{
			pTemp = pTemp->pNext;
		}
		free(g_pEnd);
		g_pEnd = pTemp;
		g_pEnd->pNext = NULL;
	}
}

//ɾ��ָ�����ݵĽ��
void deleteNodeFromList(int val)
{
	//�����ж�
	if (NULL == g_pHead)
	{
		printf("����ΪNULL�������ͷ�\n");
		return;
	}

	struct Node *pTemp = findNodeFromList(val);
	if (NULL == pTemp)
	{
		printf("���޴˽��\n");
		return;
	}

	if (pTemp == g_pHead)   //ɾ������ͷ���
	{
		DeleteNodeFromListHead();
	}
	else if (pTemp == g_pEnd)   //ɾ������β���
	{
		DeleteNodeFromListTail();
	}
	else             //ɾ�������м���
	{
		struct Node *pt = g_pHead;
		while (pt->pNext != pTemp)
		{
			pt = pt->pNext;
		}
		pt->pNext = pTemp->pNext;
		free(pTemp);
	}

}

