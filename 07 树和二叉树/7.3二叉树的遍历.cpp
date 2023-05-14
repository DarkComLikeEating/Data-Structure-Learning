//�������
void PreOrder(BTNode * b) {
    if (b != NULL) {
        printf("%c", b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

//�������
void InOrder(BTNode * b) {
    if (b != NULL) {
        InOrder(b->lchild);
        printf("%c", b->data);
        InOrder(b->rchild);
    }
}

//�������
void PostOrder(BTNode * b) {
    if (b != NULL) {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c", b->data);
    }
}