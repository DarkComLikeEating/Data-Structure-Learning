BTNode * CreateBT2(char * post, char * in, int n) {
    BTNode * b;
    char r, * p;
    int k;
    if (n <= 0) {
        return NULL;
    }
    r = * (post + n - 1);
    b = (BTNode *) malloc (sizeof(BTNode));
    b->data = r;
    for (p = in; p < in + n; p ++) {
        if (* p == r) break;
    }
    k = p - in;
    b->lchild = CreateBT2(post, in, k);
    b->rchild = CreateBT2(post + k, p + 1, n - k + 1);
    return b;
}