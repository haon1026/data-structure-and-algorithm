//ʱ�䣺2019��7��26��14:49:06
//�п�ͷ����

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *pNext;
};

//ͷβָ�붨��
struct Node *g_pHead = NULL;
struct Node *g_pEnd = NULL;

//������ͷ
void InitListHead();

//�����½��
struct Node *CreateNode(int val);

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

//ɾ��ͷ��㣨��һ����Ч��㣩
void DeleteListHead();

//ɾ��β���
void DeleteListTail();

//ɾ��ָ�����
void DeleteListRand(int val);

//�ͷ�����
void freeList();

int main()
{
	InitListHead();
	
	AddListTail(8); 
	ListTraversal();

	DeleteListHead();
	ListTraversal();

	AddListTail(10);
	ListTraversal();


	system("pause");
	return 0;
}

//������ͷ���
void InitListHead()
{
	//������ͷ���
	g_pHead = (struct Node *)malloc(sizeof(struct Node));   //�����ڴ�ռ�
	g_pHead->pNext = NULL;   
	g_pEnd = g_pHead;    //β����ʱҪ��ͷ���ָ��ͬһ����ַ
}

//�����½��
struct Node *CreateNode(int val)
{
	struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
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
void AddListTail(int val)
{
	struct Node *pNew = CreateNode(val);
	if (NULL == pNew)
	{
		printf("�����ڴ�ռ�ʧ�ܣ��ڴ治��\n");
		return;
	}
	//����
	g_pEnd->pNext = pNew;     //�����������޽�㣬����β������һ��������½��
	g_pEnd = pNew;
}

//����ͷ���
void AddListHead(int val)
{
	struct Node *pNew = CreateNode(val);
	if (NULL == pNew)
	{
		printf("�����ڴ�ռ�ʧ�ܣ��ڴ治��\n");
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
void AddListRand(int index, int val)
{
	struct Node *pTemp = FindNode(index);   //Ҳ�������ж��Ƿ�Ϊ���ڲ���

	if (NULL == pTemp)
	{
		printf("���޴˽�㣬�޷����!\n");
		return;
	}

	struct Node *pNew = CreateNode(val);
	if (NULL == pNew)
	{
		printf("�����ڴ�ռ�ʧ�ܣ��ڴ治��\n");
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
struct Node *FindNode(int val)
{
	if (NULL == g_pHead->pNext)
	{
		printf("����Ϊ�գ��޷�����");
		return NULL;
	}

	struct Node *pTemp = g_pHead->pNext;
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
void ListTraversal()
{
	if (NULL == g_pHead->pNext)
	{
		printf("����Ϊ��\n");
		return;
	}

	struct Node *pTemp = g_pHead->pNext;
	while (pTemp != NULL)
	{
		printf("%d  ", pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}

//ɾ��ͷ��㣨��һ����Ч��㣩
void DeleteListHead()
{
	if (NULL == g_pHead->pNext)
	{
		printf("����Ϊ�գ��޷�����ɾ����\n");
		return;
	}
	//����Ϊ��
	struct Node *pTemp = g_pHead->pNext;
	g_pHead->pNext = pTemp->pNext;

	//if (pTemp == g_pEnd)   //���������ֻʣһ����Ч��㣬��������β��㣬ɾ����β���Ҫ����ָ���ͷ���ָ��Ŀռ䣻
	//{
	//	g_pEnd = g_pHead;
	//}
	free(pTemp);
}

//ɾ��β���
void DeleteListTail()
{
	if (NULL == g_pHead->pNext)
	{
		printf("����Ϊ�գ��޷�����ɾ����\n");
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
		struct Node *pTemp = g_pHead->pNext;
		while (pTemp->pNext != g_pEnd)   //�����ж����㣬��Ϊβ����ڵ�һ����Ч��������Ѿ����ǹ������Կ���ֱ�Ӵӵڶ�����Ч��㿪ʼ��
		{
			pTemp = pTemp->pNext;
		}
		free(g_pEnd);
		pTemp->pNext = NULL;
		g_pEnd = pTemp;

		//д��2
		/*struct Node *pTemp = g_pHead->pNext;
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
void DeleteListRand(int val)
{
	if (NULL == g_pHead->pNext)
	{
		printf("����Ϊ�գ��޷�����ɾ����\n");
		return;
	}

	//û���ҵ�ָ�����
	struct Node *pTemp = FindNode(val);
	if (NULL == pTemp)
	{
		printf("���޴˽�㣬����ɾ��!\n");
		return;
	}

	if (pTemp == g_pEnd)   //ָ�������β���
	{
		DeleteListTail();
	}
	else           //ָ����㲻��β���
	{
		struct Node *pt = g_pHead;
		while (pt->pNext != pTemp)     //�ӵ�һ����Ч��㿪ʼ����
		{
			pt = pt->pNext;
		}
		pt->pNext = pTemp->pNext;
		free(pTemp);
	}
}

//�ͷ�����
void freeList()
{
	struct Node *pTemp = g_pHead; // g_pHead->pNext /  g_pHead    //����ǳ������ʩ��������Ҫ�ѿ�ͷ���Ҳɾ��������Ǵ���ɾ���󻹿��Լ�����ӾͲ���ɾ��
	while (pTemp != NULL)
	{
		struct Node *pT = pTemp;
		pTemp = pTemp->pNext;
		free(pT);
	}
	g_pEnd = NULL;
	g_pHead = NULL;
}
