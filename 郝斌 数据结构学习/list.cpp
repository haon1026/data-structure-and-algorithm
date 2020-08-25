# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, *PNODE;                     //NODE�ȼ���struct Node  PNODE�ȼ���struct Node *

//��������
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE);
int length_list(PNODE);
bool insert_list(PNODE, int , int);
bool delete_list(PNODE, int , int *);
void sort_list(PNODE);


int main(void)
{
	int val;
	PNODE pHead = NULL;
	pHead = create_list();       //����һ����ѭ�������������������ͷ��㸳��pHead
	traverse_list(pHead);
	int len = length_list(pHead);
	printf("������Ϊ%d\n", len);
	sort_list(pHead);
	traverse_list(pHead);

	if(insert_list(pHead, 0, 5))
	{
		printf("����������ݳɹ�\n");
	}
	else
	{
		printf("�����������ʧ��\n");
	}
	traverse_list(pHead);

	if( delete_list(pHead, 4, &val) )
	{
		printf("ɾ���ɹ�����ɾ����Ԫ����:%d\n", val);
	}
	else
	{
		printf("ɾ��ʧ��!��ɾ����Ԫ�ز�����\n");
	}
	traverse_list(pHead);

	if( is_empty(pHead))
	{
		printf("����Ϊ��\n");
	}
	else
	{
		printf("����Ϊ��\n");
	}

	
	return 0;
}

PNODE create_list(void)
{
	int len;
	int i;
	int val;  //��ʱ����û�����Ľ���ֵ
    
	//����һ���������Ч���ݵ�ͷ���
	PNODE pHead = (PNODE)malloc( sizeof(NODE) );
	if( NULL == pHead )
	{
		printf("����ʧ�ܡ�������ֹ��\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	
	printf("����������Ҫ���ɵ�������ĸ�����len = ");
	scanf("%d", &len);
	
	for(i=0; i<len; ++i)
	{
		printf("�������%d������ֵ��", i+1);
		scanf("%d", &val);
		
		PNODE pNew = (PNODE)malloc( sizeof(NODE));
		if( NULL == pHead )
		{
			printf("����ʧ�ܡ�������ֹ��\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;

	while( NULL != p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");

	return;
}

bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
		return true;
	else
		return false;
}

int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;

	while( NULL != p)
	{
		++len;
		p = p->pNext;
	}

	return len;
}

void sort_list(PNODE pHead)
{
/*	int i, j, t;
	int len = length_list(pHead);
	PNODE p, q;
	
	for(i=0,p=pHead->pNext; i<len; ++i,p=p->pNext)             //for(p=pHead->pNext; p!=NULL; p=p->pNext)
	{
		for(j=i+1,q=p->pNext; j<len-1; ++j,q=q->pNext)         //for(q=p->pNext; q!=NULL; q=q->pNext)
		{
			if(p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
*/
	PNODE p = pHead->pNext;
	PNODE q = p->pNext;
	int t;
	while(p != NULL)
	{
		q = p->pNext;
		while(q != NULL)
		{
			if(p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
			q = q->pNext;
		}
		p = p->pNext;
	}

	return;
}

bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;

	while(NULL!=p && i<pos-1)     //pos>1,whileѭ���ų���
	{
		p = p->pNext;
		++i;
	}
	if(i>pos-1 || NULL==p)                 //i > pos -1�Ƿ�ֹ���������pos����Ϊ0���߸������ⶼ�����ⲻ���ϡ�NULL == p�أ��Ƿ�ֹ��������ĳ��ȶ���û��pos������������pos���λ�ÿ��Բ��롣
		return false;
	PNODE pNew = (PNODE)malloc( sizeof(NODE) );
	if(NULL == pNew)
	{
		printf("��̬�����ڴ�ʧ��");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
		
/*	int len;
	len = length_list(pHead);
	if(pos<1 || pos>len+1)
	{
		return false;
	}

	int i;
	PNODE p = pHead;
	PNODE q = (PNODE)malloc( sizeof(NODE) );
	if(NULL == q)
	{
		printf("��̬�����ڴ�ʧ��");
		exit(-1);
	}
    
	for(i=1; i<pos; ++i)
	{
		p = p->pNext;
	}

	q->data = val;
	q->pNext = p->pNext;
	p->pNext = q;
*/
	return true;
}

bool delete_list(PNODE pHead, int pos, int * val)
{
	int i = 0;
	PNODE p = pHead;

	while(NULL!=p->pNext && i<pos-1)
	{
		p = p->pNext;
		++i;
	}
	if(i>pos-1 || NULL==p->pNext)
		return false;

	PNODE q = p->pNext;                         
	*val = q->data;

	//ɾ��p����Ľ��
	p->pNext = p->pNext->pNext;
	free(q);                           //�ѽڵ�1ָ����ָ��ָ��ڵ�3������Ҫ�����ͷŽڵ�2��ռ���ڴ棬���򽫻�����ڴ�й©
	q = NULL;

	return true;
}
