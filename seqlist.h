#pragma once
#include <stdio.h>
/*
typedef struct seqList
{
	//��Сȷ��,һ�㲻Ҫ̫����Ϊ��̬�ռ��ǿ���ջ�ռ��ϵģ�ջ�ռ���Ƚ϶��ԱȽ�С
	int _array[100];
	int _size;
}seqList;*/

typedef int DataType;//���ͱ��������Ӵ���������

typedef struct seqList
{
	DataType *_array;
	unsigned int _size;//������size_t _size��Ҳ���޷������ͣ�����Ҫ����ͷ�ļ�#include<stdio.h>
	unsigned int _capacity;
}seqList;


void seqListInit(seqList* sl);
void seqListPushBack(seqList* sl,DataType value);//β��
void seqListPopBack(seqList* sl);//βɾ
void seqListPushFront(seqList* sl,DataType value);//ͷ��
void seqListPopFront(seqList* sl);//ͷɾ
void seqListPushInsert(seqList* sl,size_t pos,DataType value);//��ĳ���ط�����һ��Ԫ��
void seqListErase(seqList* sl,size_t pos);//ɾ��posλ�õ�Ԫ��
int seqListFind(seqList* sl,DataType value);//����
void seqListPrint(seqList* sl);//��ӡ
void checkCapacity(seqList* sl);