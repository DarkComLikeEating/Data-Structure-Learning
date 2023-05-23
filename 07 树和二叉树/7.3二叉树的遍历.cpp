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
















////////////��������Դ�ļ�////////////
/*
#include <iostream>
#include "7.2�������Ļ�������.cpp"
#include "7.3�������ı���.cpp"

using namespace std;

int main() {
    char str[100] = "A(B(D(,G)),C(E,F))";
    BTNode * BT;
    CreateBTree(BT, str);
    cout << "�������: ";
    PreOrder(BT);
    cout << endl;

    cout << "�������: ";
    InOrder(BT);
    cout << endl;

    cout << "�������: ";
    PostOrder(BT);
    cout << endl;

    DestoryBTree(BT);
    return 0;

    /*
    ���Խ��:
    �������: ABDGCEF       
    �������: DGBAECF
    �������: GDBEFCA
    */
}
*/