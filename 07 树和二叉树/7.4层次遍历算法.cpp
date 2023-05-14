#include <iostream>
#define ElemType int

using namespace std;
const int MaxSize = 50;

void LevelOrder(BTNode * b) {
    BTNode * p;
    SqQueue * qu;
    InitQueue(qu);
    EnQueue(qu, b);
    while (!QueueEmpty(qu)) {
        DeQueue(qu, p);
        printf("%c", p->data);
        if (p->lchild != NULL) {
            EnQueue(qu, p->lchild);
        } 
        if (p->rchild != NULL) {
            EnQueue(qu, p->rchild);
        }
    }
}