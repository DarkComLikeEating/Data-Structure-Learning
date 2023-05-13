/*
建立顺序表 CreatList(&L, a[], n)
初始化线性表 InitList(&L)
销毁线性表 DestroyList(&L)
判断线性表是否为空表 ListEmpty(L)
求线性表的长度 ListLength(L)
输出线性表 DispList(L)
按序号求线性表中的元素 GetElem(L, i, &e)
按元素值查找 LocateElem(L, e)
插入元素数据 ListInsert(&L, i, e)
删除元素数据 ListDelete(&L, i, &e)
*/

#include <iostream>
#include <malloc.h>

using namespace std;

const int MaxSize = 50; 

typedef struct {
	int data[MaxSize];
	int length;
} SqList;

void CreateList(SqList * &L, int a[], int n) {
	int i = 0, k = 0;
	L = (SqList * ) malloc (sizeof(SqList));
	while (i < n) {
		L->data[k] = a[i];
		k ++; i ++;		
	}
	L->length = k;
}

void InitList(SqList * &L) {
	L = (SqList * ) malloc (sizeof(SqList));
	L->length = 0;
}

void DestoryList(SqList * L) {
	free(L);
}

bool ListEmpty(SqList * L) {
	return (L->length == 0);
}

int ListLength(SqList * L) {
	return (L->length);
}

void DispList(SqList * L) {
	for (int i = 0; i < L->length; i ++) 
		cout << L->data[i] << " ";
	cout << endl;
}

bool GetElem(SqList * L, int i, int &e) {
	if (i < 1 || i > L->length) 
		return false;
	e = L->data[i - 1];
	return true;
}

int LocateElem(SqList * L, int e) {
	int i = 0;
	while (i < L->length && L->data[i] != e) 
		i ++;
	if (i >= L->length)
		return 0;
	else 
		return i + 1;
}

bool ListInsert(SqList * &L, int i, int e) {
	if (i < 1 || i > L->length + 1)
		return false;
	i --;
	for (int j = L->length; j > i; j --) 
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length ++;
	return true;
}

bool ListDelete(SqList * &L, int i, int &e) {
	if (i < 1 || i > L->length)
		return false;
	i --;
	e = L->data[i];
	for (int j = 1; i < L->length - 1; j ++) 
		L->data[j] = L->data[j + 1];
	L->length --;
	return true;
}
