#define ElemType char;

typedef struct node {
    ElemType data;
    int ltag, rtag;
    struct node * lchild;
    struct node * rchild;
} TBTNode;

//中序线索二叉树
TBTNode * pre;
void Thread(TBTNode * &p) {
    if (p != NULL) {
        Thread(p->lchild);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        } else {
            p->ltag = 0;
        }
        if (pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        } else {
            pre->rtag = 0;
        }
        pre = p;
        Thread(p->rchild);
    }
}

TBTNode * CreateThread(TBTNode * b) {
    TBTNode * root;
    root = (TBTNode *) malloc (sizeof(TBTNode));
    root->ltag = 0;
    root->rtag = 1;
    root->rchild = b;
    if (b == NULL) {
        root->lchild = root;
    } else {
        root->lchild = b;
        pre = root;
        Thread(b);
        pre->rchild = root;
        pre->rtag = 1;
        root->rchild = pre;
    }
    return root;
}

//遍历线索化二叉树
void ThInOrder(TBTNode * tb) {
    TBTNode * p = tb->lchild;
    while (p != tb) {
        while (p->ltag == 0) p = p->lchild;
        printf("%c", p->data);
        while (p->rtag == 1 && p->rchild != tb) {
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
}