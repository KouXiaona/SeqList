#pragma once
#include <stdio.h>
/*
typedef struct seqList
{
	//大小确定,一般不要太大，因为静态空间是开在栈空间上的，栈空间相比较而言比较小
	int _array[100];
	int _size;
}seqList;*/

typedef int DataType;//类型别名，增加代码的灵活性

typedef struct seqList
{
	DataType *_array;
	unsigned int _size;//或者用size_t _size；也是无符号整型，不过要包含头文件#include<stdio.h>
	unsigned int _capacity;
}seqList;


void seqListInit(seqList* sl);
void seqListPushBack(seqList* sl,DataType value);//尾插
void seqListPopBack(seqList* sl);//尾删
void seqListPushFront(seqList* sl,DataType value);//头插
void seqListPopFront(seqList* sl);//头删
void seqListPushInsert(seqList* sl,size_t pos,DataType value);//在某个地方插入一个元素
void seqListErase(seqList* sl,size_t pos);//删除pos位置的元素
int seqListFind(seqList* sl,DataType value);//查找
void seqListPrint(seqList* sl);//打印
void checkCapacity(seqList* sl);