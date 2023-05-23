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
















////////////测试数据源文件////////////
/*
#include <iostream>
#include "7.2二叉树的基本运算.cpp"
#include "7.3二叉树的遍历.cpp"

using namespace std;

int main() {
    char str[100] = "A(B(D(,G)),C(E,F))";
    BTNode * BT;
    CreateBTree(BT, str);
    cout << "先序遍历: ";
    PreOrder(BT);
    cout << endl;

    cout << "中序遍历: ";
    InOrder(BT);
    cout << endl;

    cout << "后序遍历: ";
    PostOrder(BT);
    cout << endl;

    DestoryBTree(BT);
    return 0;

    /*
    测试结果:
    先序遍历: ABDGCEF       
    中序遍历: DGBAECF
    后序遍历: GDBEFCA
    */
}
*/