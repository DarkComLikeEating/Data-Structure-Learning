/*
ѭ������
ͳ��ֵΪx������ count(L, x)
ɾ��ֵΪx��� deletem(&L, x)
�ж����ݽ���Ƿ�Գ� Symm(L) 
*/

#include <iostream>
#include <malloc.h>

using namespace std;

int count(LinkNode * L, int x) {
	int i = 0;
	LinkNode * p = L->next;
	while (p != L) {
		if (p->data == x) {
			i ++;
		} 
		p = p->next;
	}
	return i;
}

bool deletem(DLinkNode * &L, int x) {
	DLinkNode * p = L->next;
	while (p != L && p->data != x) {
		p = p->next;
	}
	if (p != L) {
		p->next->piror = p->prior;
		p->prior->next = p->next;
		return true;
	} else {
		return false;
	}
}

bool Symm(DLinkNode * L) {
	bool same = true;
	DLinkNode * p = L->next;
	DLinkNode * q = L->prior;
	while (same) {
		if (p->data != q->data) {
			same = false;
		} else {
			if (p == q || p == q->prior) break;
			q = q->prior;
			p = p->next;
		}
		return same;
	}
}
