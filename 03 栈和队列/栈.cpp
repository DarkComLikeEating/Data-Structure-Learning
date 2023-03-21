/*
栈
初始化栈 InitStack(&s)
销毁栈 DestroyStack(&s)
判断栈是否为空 StackEmpty(s)
进栈 Push(&s, e)
出栈 Pop(&s, &e)
取栈顶元素 GetTop(s, &e) 
*/ 

#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct linknode {
	int data;
	struct linknode * next;
} LinkStNode;

void InitStack(LinkStNode * &s) {
	s = (LinkStNode * ) malloc (sizeof(LinkStNode));
	s->next = NULL;
}

void DestroyStack(LinkStNode * &s) {
	LinkStNode * pre = s, * p = s->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

bool StackEmpty(LinkStNode * s) {
	return (s->next == NULL);
}

void Push(LinkStNode * &s, int e) {
	LinkStNode * p;
	p = (LinkStNode * ) malloc (sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

bool Pop(LinkStNode * &s, int &e) {
	LinkStNode * p;
	if (s->next == NULL) {
		return false;
	}
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}

bool GetTop(LinkStNode * s, int &e) {
	if (s->next == NULL) {
		return false;
	}
	e = s->next->data;
	return true;
}
