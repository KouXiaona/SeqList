#include "seqlist.h"
#include <stdlib.h>

	void seqListInit(seqList* sl)//初始化
	{
		//初始化数组
		sl->_array = (int *)malloc(sizeof(DataType)* 4);
		sl->_capacity = 4;
		sl->_size = 0;
	}
	
	void seqListPushBack(seqList* sl, DataType value)//尾插
	{
		sl->_array[sl->_size++] = value;
		//把value赋值给数组有效数据_size的下一个地方
	}
	void seqListPopBack(seqList* sl)//尾删
	{
		//删除只是让空间内的元素变成无效，不释放空间
		if (sl->_size)
		{
			--sl->_size;
		}
	}
	
	void seqListPushFront(seqList* sl, DataType value)//头插
	{
		//把元素放在零的位置，如果直接放的话会覆盖其他元素，所以要先移开。
		//	从后向前移，若是从前向后的话那就是将原来的第零个位置复制了一整个数组
		checkCapacity(&sl);
		size_t end = sl->_size;//元素从后向前移动，防止元素覆盖
		while (end > 0)
		{
			sl->_array[end] = sl->_array[end-1];
			--end;
		}
		sl->_array[0] = value;
		++sl->_size;
	}

	void seqListPushFront1(seqList* sl, DataType value)//头插
	{
		//seqListPushInsert(sl, 0, value);
		seqListPushInsert(sl, sl->_size, value);//尾插
	}
	/*
	void seqListPushFront(seqList* sl, DataType value)//头插
	{
		//把元素放在零的位置，如果直接放的话会覆盖其他元素，所以要先移开。
		//	从后向前移，若是从前向后的话那就是将原来的第零个位置复制了一整个数组

		int end = sl->_size-1;//元素从后向前移动，防止元素覆盖
		while (end >= 0)
		{
			sl->_array[end+1] = sl->_array[end ];
			--end;
		}
		sl->_array[0] = value;
		++sl->_size;
	}*/

	


	void seqListPushInsert(seqList* sl, size_t pos, DataType value)//在某个地方插入一个元素
	{
		//判断位置是否合法
		if (pos <= sl->_size)//如果POS等于size，就是尾插
		{
			//检查容量
			checkCapacity(sl);
			//移动元素 从pos--size-1
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
	void seqListErase(seqList* sl, size_t pos)//删除pos位置的元素
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

	int seqListFind(seqList* sl, DataType value)//查找
	{
		//其实就是一个简单地遍历过程
		for (int i = 0; i < sl->_size; i++)
		{
			if (sl->_array[i] == value)
				return i;
		}
		return -1;
	}

	
	void seqListPopFront(seqList* sl)//头删
	{
		//把后面的位置全部向前挪动一位，从头开始挪
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
	void seqListPrint(seqList* sl)//打印
	{
		for (size_t i = 0; i < sl->_size; i++)
		{
			printf("%d", sl->_array[i]);
		}
		printf("\n");
	}
	void checkCapacity(seqList* sl)//增容
	{
		if (sl->_size == sl->_capacity)
		{
			sl->_capacity *= 2;
			//开空间
			DataType* newArray = (DataType*)malloc(sizeof(DataType)*sl->_capacity);
			//拷贝
			memcpy(newArray, sl->_array, sl->_size*sizeof(DataType));
			//释放空间
			free(sl->_array);
			sl->_array = newArray;

			//sl->_array = (DataType*)realloc(sl->_array, sizeof(DataType)*sl->_capacity);//相当于上面好多步
		}
	}

	void test()
	{
		seqList sl;
		seqListInit(&sl);
		seqListPushBack(&sl, 1);//插入
		seqListPrint(&sl);
		seqListPushBack(&sl, 2);
		seqListPrint(&sl);
		seqListPushBack(&sl, 3);
		seqListPrint(&sl);
		seqListPushFront(&sl, 6);
		seqListPrint(&sl);
		seqListPopBack(&sl);//删除
		seqListPrint(&sl);
		seqListPopBack(&sl);
		seqListPrint(&sl);
		seqListPopFront(&sl);//头删
		seqListPrint(&sl);
		seqListPushInsert(&sl, 1, 9);//在1位置插入9
		seqListPrint(&sl);
		seqListPushFront1(&sl, 8);//尾删，接口的复用
		seqListPrint(&sl);
		seqListErase(&sl, 0);//删除0位置的元素
		seqListPrint(&sl);
		printf("%d",seqListFind(&sl, 8));//查找
	}
int main()
{
	test();
	system("pause");
	return 0;
}