/*
单链表
头插法建立单链表 CreateListF(&L, a[], n)
尾插法建立单链表 CreateListR(&L, a[], n)
初始化 InitList(&L)
销毁 DestroyList(&L)
判断是否为空 ListEmpty(L)
求长度 ListLength(L)
输出 DispList(L)
求某个数据元素值 GetElmem(L, i, &e)
按元素值查找 LocateElem(L, e)
插入数据元素 ListInsert(&L, i, e) 
删除数据元素 ListDelete(&L, i, &e) 
*/

#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode * next;
} LinkNode; 

void CreateListF(LinkNode * &L, int a[], int n) {
	LinkNode * s;
	L = (LinkNode *) malloc (sizeof(LinkNode));
	L->next = NULL;		//创建头结点，其next设为NULL
	for (int i = 0; i < n; i ++) {
		s = (LinkNode *) malloc (sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;	
		L->next = s;
	} 
}

void CreateListR(LinkNode * &L, int a[], int n) {
	LinkNode * s, * r;
	L = (LinkNode *) malloc (sizeof(LinkNode));	//创建头结点
	r = L;
	for (int i = 0; i < n; i ++) {
		s = (LinkNode *) malloc (sizeof(LinkNode));
		s->data = a[i];
		r->next = s;	//第一次是将s插入到头结点(r = L)之后，随后都是插入到r之后
		r = s;
	}
	r->next = NULL;
} 

void InitList(LinkNode * &L) {
	L = (LinkNode *) malloc (sizeof(LinkNode));
	L->next = NULL;
}

void DestroyList(LinkNode * &L) {
	LinkNode * pre = L, * p = L->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

bool ListEmpty(LinkNode * L) {
	return (L->next == NULL);
}

int ListLength(LinkNode * L) {
	int n = 0;
	LinkNode * p = L;
	while (p->next != NULL) {
		n ++;
		p = p->next;
	}
	return n;
}

void DispList(LinkNode * L) {
	LinkNode * p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

bool GetElem(LinkNode * L, int i, int &e) {
	int j = 0;
	LinkNode * p = L;
	if (i <= 0) return false;
	while (j < i && p != NULL) {
		j ++;
		p = p->next;
	}
	if (p = NULL) {
		return false;
	} else {
		e = p->data;
		return true;
	}
}

bool ListInsert(LinkNode * &L, int i, int e) {
	int j = 0;
	LinkNode * p = L, * s;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL) {
		j ++;
		p = p->next;
	}
	if (p == NULL) {
		return false;
	} else {
		s = (LinkNode *) malloc (sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

bool ListDelete(LinkNode * &L, int i, int &e) {
	int j = 0;
	LinkNode * p = L, * q;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL) {
		j ++;
		p = p->next;
	}
	if (p == NULL) {
		return false;
	} else {
		q = p->next;
		if (q == NULL) {
			return false;
		}
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}
