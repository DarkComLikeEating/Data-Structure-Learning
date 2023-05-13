/*
˫���� 
ͷ�巨����˫���� CreateListF(&L, a[], n)
β�巨����˫���� CreateListR(&L, a[], n)
��������Ԫ�� ListInsert(&L, i, e)
ɾ������Ԫ�� ListDelete(&L, i, &e) 
*/

#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct DNode {
	int data;
	struct DNode * prior;
	struct DNode * next;
} DLinkNode;

void CreateListF(DLinkNode * &L, int a[], int n) {
	DLinkNode * s;
	L = (DLinkNode * ) malloc (sizeof(DLinkNode));
	L->prior = L->next = NULL;
	for (int i = 0; i < n; i ++) {
		s = (DLinkNode * ) malloc (sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL) {
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;
	}
}

void CreateListR(DLinkNode * &L, int a[], int n) {
	DLinkNode * s, * r;
	L = (DLinkNode * ) malloc (sizeof(DLinkNode));
	r = L;
	for (int i = 0; i < n; i ++) {
		s = (DLinkNode * ) malloc (sizeof(DLinkNode));
		s->data = a[i];
		r->next = s; s->prior = r;
		r = s;
	}
	r->next = NULL;
}

bool ListInsert(DLinkNode * &L, int i, int e) {
	int j = 0;
	DLinkNode * p = L, * s;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL) {
		j ++;
		p = p->next;
	}
	if (p == NULL) {
		return false;
	} else {
		s = (DLinkNode * ) malloc (sizeof(DLinkNode));
		s->data = e;
		s->next = p->next;
		if (p->next != NULL) {
			p->next->prior = s;
		}
		s->prior = p;
		p->next = s;
		return true;
	}
}

bool ListDelete(DLinkNode * &L, int i, int &e) {
	int j = 0;
	DLinkNode * p = L, * q;
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
		if (p->next != NULL) {
			p->next->prior = p;
		}
		free(q);
		return true;
	}
}
