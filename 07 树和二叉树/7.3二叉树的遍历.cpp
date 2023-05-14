//先序遍历
void PreOrder(BTNode * b) {
    if (b != NULL) {
        printf("%c", b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

//中序遍历
void InOrder(BTNode * b) {
    if (b != NULL) {
        InOrder(b->lchild);
        printf("%c", b->data);
        InOrder(b->rchild);
    }
}

//后序遍历
void PostOrder(BTNode * b) {
    if (b != NULL) {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c", b->data);
    }
}