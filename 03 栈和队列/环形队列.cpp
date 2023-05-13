/*
���ζ���
��ʼ������ InitQueue(&q) 
���ٶ��� DestroyQueue(&q)
�ж϶����Ƿ�Ϊ�� QueueEmpty(q)
������ EnQueue(&q, e)
������ DeQueue(&q, &e)
*/

#include <iostream>
#include <malloc.h>

using namespace std;

const int Maxsize = 100;

typedef struct {
	int data[Maxsize];
	int front, rear;
} SqQueue;

void InitQueue(SqQueue * &q) {
	q = (SqQueue * ) malloc (sizeof(SqQueue));
	q->front = 0;
	q->rear = 0
}

void DestroyQueue(SqQueue * & q) {
	free(q);
}

bool QueueEmpty(SqQueue * q) {
	return (q->front == q->rear);
}

bool EnQueue(SqQueue * &q, int e) {
	if ((q->rear + 1) % Maxsize == q->front) {
		return false;
	}
	q->rear = (q->rear + 1) % Maxsize;
	q->data[q->rear] e;
	return true;
}

bool DeQueue(SqQueue * &q, int &e) {
	if (q->front = q->rear) {
		return false;
	}
	q->front = (q->front + 1) % Maxsize;
	e = q->data[q->front];
	return true;
}
