#include <iostream>
#define ElemType char

using namespace std;
const int MaxSize = 50;

// ˫�״洢�ṹ
typedef struct {
    ElemType data;
    int parent;
} PTree[MaxSize];

// �������洢�ṹ
typedef struct node {
    ElemType data;
    struct node * sons[MaxSize];    //MaxSizeΪ���ĺ��ӽ����������Ϊ�����Ķ�
} TSonNode;