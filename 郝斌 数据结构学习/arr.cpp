# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

struct Arr
{
	int * pBase;  //�洢�����һ��Ԫ�صĵ�ַ
	int len;      //�����������ɵ����Ԫ�صĸ���
	int cnt;      //��ǰ������Ч����
	//int increment; �Զ���������
};

void init_arr(struct Arr * pArr, int length);
bool append_arr(struct Arr * pArr, int val);  //׷��
bool insert_arr(struct Arr * pArr, int pos, int val);//pos��ֵ��1��ʼ  
bool delete_arr(struct Arr * pArr, int pos, int *pVal);//�����Ƿ�ɹ�ɾ������ɾ��Ԫ��
int get();
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
void sort_arr(struct Arr * pArr);
void show_arr(struct Arr * pArr);
void inversion_arr(struct Arr * pArr);


int main(void)
{
	struct Arr arr;
	int val;
	
	init_arr(&arr, 6);      //��ʼ��
	show_arr(&arr);         //Ԫ����ʾ

	append_arr(&arr, 1);    //׷��Ԫ��
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	show_arr(&arr);
	printf("\n");

	if ( append_arr(&arr, 5) )
	{
		printf("׷�ӳɹ�!\n");
	}
	else
	{
		printf("׷��ʧ��!\n");
	}
	show_arr(&arr);
	printf("\n");

	//insert_arr(&arr, 6 , 99);         //Ԫ�ز���
	if( insert_arr(&arr, 6, 99) )
	{
		printf("����ɹ�!\n");
	}
	else
	{
		printf("����ʧ��!\n");
	}
	show_arr(&arr);
	printf("\n");

	//delete_arr(&arr, 1, &val)
	if( delete_arr(&arr, 1, &val) )   //ɾ��Ԫ��
	{
		printf("ɾ���ɹ���\n");
		printf("��ɾ����Ԫ���ǣ�%d\n", val);
	}
	else
	{
		printf("ɾ��ʧ�ܣ�\n");
	}
	show_arr(&arr);
	printf("\n");

    inversion_arr(&arr);    //����Ԫ�ص���
	printf("���ú�");
	show_arr(&arr);
	printf("\n");

	sort_arr(&arr);         //Ԫ������
	printf("�����");
	show_arr(&arr);
	printf("\n");

	return 0;
}

void init_arr(struct Arr * pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if ( NULL == pArr->pBase)
	{
		printf("��̬�ڴ����ʧ��");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

void show_arr(struct Arr * pArr)
{
	int i;
	if ( is_empty(pArr) )
	{
		printf("����Ϊ��\n");
	}
	else
	{
		printf("����Ԫ��Ϊ��");
		for(i=0; i<pArr->cnt; ++i)
		{
			printf("%d ", pArr->pBase[i]);
		}
		printf("\n");
	}
	
	
}

bool is_empty(struct Arr * pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
	
}

bool is_full(struct Arr * pArr)
{
	if(pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

bool append_arr(struct Arr * pArr, int val)
{
	//��ʱ����false
	if( is_full(pArr) )
		return false;
	//����ʱ׷��
	else	
		pArr->pBase[pArr->cnt] = val;
	pArr->cnt++;
	return true;
}

bool insert_arr(struct Arr * pArr, int pos, int val)
{
	int i;
	
    if( is_full(pArr) )
		return false;
	
	if(pos<1 || pos>pArr->cnt+1)
		return false;
	
	for(i=pArr->cnt; i>=pos; i--)     //i=pArr->cnt-1;i>=pos-1;--i;
	{
		pArr->pBase[i] = pArr->pBase[i-1];  //pArr->pBase[i+1] = pArr->pBase[i]
		
	}
	pArr->pBase[i] = val;
	pArr->cnt++;
	return true;
}

bool delete_arr(struct Arr * pArr, int pos, int *pVal)
{
	int i;
	if( is_empty(pArr) )
		return false;
	if( pos<1 || pos>pArr->cnt )
		return false;
	
	*pVal = pArr->pBase[pos-1];
	for(i=pos; i<pArr->cnt; ++i)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
		pArr->cnt--;

		return true;
}

void inversion_arr(struct Arr * pArr)
{
	int i = 0;
	int j = pArr->cnt-1;
	int t;

	while(i < j)
	{
		t = pArr->pBase[j];
		pArr->pBase[j] = pArr->pBase[i];
		pArr->pBase[i] = t;
		++i;
		--j;
	}
	return;
}

void sort_arr(struct Arr * pArr)
{
	int i, j, t;

	for(i=0; i<pArr->cnt; ++i)
		for(j=i+1; j<pArr->cnt; ++j)
		{
			if(pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[j];
				pArr->pBase[j] = pArr->pBase[i];
				pArr->pBase[i] = t;
			}

		}
}