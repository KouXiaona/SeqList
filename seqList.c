#include "seqlist.h"
#include <stdlib.h>

	void seqListInit(seqList* sl)//��ʼ��
	{
		//��ʼ������
		sl->_array = (int *)malloc(sizeof(DataType)* 4);
		sl->_capacity = 4;
		sl->_size = 0;
	}
	
	void seqListPushBack(seqList* sl, DataType value)//β��
	{
		sl->_array[sl->_size++] = value;
		//��value��ֵ��������Ч����_size����һ���ط�
	}
	void seqListPopBack(seqList* sl)//βɾ
	{
		//ɾ��ֻ���ÿռ��ڵ�Ԫ�ر����Ч�����ͷſռ�
		if (sl->_size)
		{
			--sl->_size;
		}
	}
	
	void seqListPushFront(seqList* sl, DataType value)//ͷ��
	{
		//��Ԫ�ط������λ�ã����ֱ�ӷŵĻ��Ḳ������Ԫ�أ�����Ҫ���ƿ���
		//	�Ӻ���ǰ�ƣ����Ǵ�ǰ���Ļ��Ǿ��ǽ�ԭ���ĵ����λ�ø�����һ��������
		checkCapacity(&sl);
		size_t end = sl->_size;//Ԫ�شӺ���ǰ�ƶ�����ֹԪ�ظ���
		while (end > 0)
		{
			sl->_array[end] = sl->_array[end-1];
			--end;
		}
		sl->_array[0] = value;
		++sl->_size;
	}

	void seqListPushFront1(seqList* sl, DataType value)//ͷ��
	{
		//seqListPushInsert(sl, 0, value);
		seqListPushInsert(sl, sl->_size, value);//β��
	}
	/*
	void seqListPushFront(seqList* sl, DataType value)//ͷ��
	{
		//��Ԫ�ط������λ�ã����ֱ�ӷŵĻ��Ḳ������Ԫ�أ�����Ҫ���ƿ���
		//	�Ӻ���ǰ�ƣ����Ǵ�ǰ���Ļ��Ǿ��ǽ�ԭ���ĵ����λ�ø�����һ��������

		int end = sl->_size-1;//Ԫ�شӺ���ǰ�ƶ�����ֹԪ�ظ���
		while (end >= 0)
		{
			sl->_array[end+1] = sl->_array[end ];
			--end;
		}
		sl->_array[0] = value;
		++sl->_size;
	}*/

	


	void seqListPushInsert(seqList* sl, size_t pos, DataType value)//��ĳ���ط�����һ��Ԫ��
	{
		//�ж�λ���Ƿ�Ϸ�
		if (pos <= sl->_size)//���POS����size������β��
		{
			//�������
			checkCapacity(sl);
			//�ƶ�Ԫ�� ��pos--size-1
			size_t end = sl->_size;
			while (end > pos)
			{
				sl->_array[end] = sl->_array[end - 1];
				--end;
			}
			sl->_array[pos] = value;
			++sl->_size;
		}
	}
	void seqListErase(seqList* sl, size_t pos)//ɾ��posλ�õ�Ԫ��
	{
		if (sl->_size)
		{
			size_t start = pos;
			while (start < sl->_size)
			{
				sl->_array[start-1] = sl->_array[start];
				++start;
			}
		}
		--sl->_size;
	}

	int seqListFind(seqList* sl, DataType value)//����
	{
		//��ʵ����һ���򵥵ر�������
		for (int i = 0; i < sl->_size; i++)
		{
			if (sl->_array[i] == value)
				return i;
		}
		return -1;
	}

	
	void seqListPopFront(seqList* sl)//ͷɾ
	{
		//�Ѻ����λ��ȫ����ǰŲ��һλ����ͷ��ʼŲ
		if (sl->_size)
		{
			size_t start = 1;
			while (start < sl->_size)
			{
				sl->_array[start - 1] = sl->_array[start];
				++start;

			}
			sl->_size--;
		}
	}
	void seqListPrint(seqList* sl)//��ӡ
	{
		for (size_t i = 0; i < sl->_size; i++)
		{
			printf("%d", sl->_array[i]);
		}
		printf("\n");
	}
	void checkCapacity(seqList* sl)//����
	{
		if (sl->_size == sl->_capacity)
		{
			sl->_capacity *= 2;
			//���ռ�
			DataType* newArray = (DataType*)malloc(sizeof(DataType)*sl->_capacity);
			//����
			memcpy(newArray, sl->_array, sl->_size*sizeof(DataType));
			//�ͷſռ�
			free(sl->_array);
			sl->_array = newArray;

			//sl->_array = (DataType*)realloc(sl->_array, sizeof(DataType)*sl->_capacity);//�൱������öಽ
		}
	}

	void test()
	{
		seqList sl;
		seqListInit(&sl);
		seqListPushBack(&sl, 1);//����
		seqListPrint(&sl);
		seqListPushBack(&sl, 2);
		seqListPrint(&sl);
		seqListPushBack(&sl, 3);
		seqListPrint(&sl);
		seqListPushFront(&sl, 6);
		seqListPrint(&sl);
		seqListPopBack(&sl);//ɾ��
		seqListPrint(&sl);
		seqListPopBack(&sl);
		seqListPrint(&sl);
		seqListPopFront(&sl);//ͷɾ
		seqListPrint(&sl);
		seqListPushInsert(&sl, 1, 9);//��1λ�ò���9
		seqListPrint(&sl);
		seqListPushFront1(&sl, 8);//βɾ���ӿڵĸ���
		seqListPrint(&sl);
		seqListErase(&sl, 0);//ɾ��0λ�õ�Ԫ��
		seqListPrint(&sl);
		printf("%d",seqListFind(&sl, 8));//����
	}
int main()
{
	test();
	system("pause");
	return 0;
}