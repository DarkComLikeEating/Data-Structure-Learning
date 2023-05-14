#include <iostream>
#define ElemType char

using namespace std;
const int MaxSize = 50;

// 双亲存储结构
typedef struct {
    ElemType data;
    int parent;
} PTree[MaxSize];

// 孩子链存储结构
typedef struct node {
    ElemType data;
    struct node * sons[MaxSize];    //MaxSize为最多的孩子结点个数，或称为该树的度
} TSonNode;