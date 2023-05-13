#include <iostream>
using namespace std;
// using ElemType = int;
#define ElemType int
// typedef int ElemType;

typedef struct qnode {
    ElemType data;
    struct qnode * next;
} DataNode;

typedef struct {
    DataNode * front;
    DataNode * rear;
} LinkQuNode;

void InitQueue(LinkQuNode * &q) {
    q = (LinkQuNode *) malloc (sizeof(LinkQuNode));
    q->rear = NULL;
    q->front = NULL; 
}

void DestroyQueue(LinkQuNode * &q) {
    DataNode * pre = q->front, * p;
    if (pre != NULL) {
        p = pre->next;
        while (p != NULL) {
            free(pre);
            pre = p;
            p = p->next;
        }
        free(pre);
    }
    free(q);
}

bool QueueEmpty(LinkQuNode * q) {
    return (q->rear == NULL);
}

void EnQueue(LinkQuNode * &q, ElemType e) {
    DataNode * p;
    p = (DataNode * ) malloc (sizeof(DataNode));
    p->data = e;
    p->next = NULL;
    if (q->rear == NULL) {
        q->rear = p;
        q->front = p;
    } else {
        q->rear->next = p;
        q->rear = p;
    }
}

bool DeQueue(LinkQuNode * &q, ElemType &e) {
    DataNode * t;
    if (q->rear == NULL) {
        return false;
    }
    t = q->front;
    if (q->front == q->rear) {
        q->rear = NULL;
        q->front = NULL;
    } else {
        q->front = q->front->next;
    }
    e = t->data;
    free(t);
    return true;
}

