#include <iostream>
#include <malloc.h>

using namespace std;

using ElemType = char;

typedef struct lnode {
    int tag;
    union {
        ElemType data;
        struct lnode * sublist;
    } val;
    struct lnode * link;
} GLNode;

//求广义表的长度
int GLLength(GLNode * g) {
    int n = 0;
    GLNode * g1;
    g1 = g->val.sublist;
    while (g1 != NULL) {
        n ++;
        g1 = g1->link;
    }
    return n;
}

//求广义表的深度
/*
递归模型：
若g为原子 f(g) = 0
若g为空表 f(g) = 1
其他情况 f(g) = MAX{f(subg)}+1 (subg是g的子表)
*/
int GLDepth(GLNode * g) {
    GLNode * g1;
    int maxd = 0, depth;
    if (g->tag == 0) {
        return 0;
    }
    g1 = g->val.sublist;
    if (g1 == NULL) {
        return 1;
    }
    while (g1 != NULL) {
        if (g1->tag == 1) {
            depth = GLDepth(g1);
            if (depth  > maxd) {
                maxd = depth;
            }
        }
        g1 = g1->link;
    }
    return maxd + 1;
}

//输出广义表
void DispGL(GLNode * g) {
    if (g != NULL) {
        if (g->tag == 0) {
            cout << g->val.data;
        } else {
            cout << "(";
            if (g->val.sublist == NULL) {
                cout << "#";
            } else {
                DispGL(g->val.sublist);
            }
            cout << ")";
        }
        if (g->link != NULL) {
            cout << ",";
            DispGL(g->link);
        }
    } 
}

//建立广义表的链式存储结构
GLNode * CreateGL(char * &s) {
    GLNode * g;
    char ch = * s ++;
    if (ch != '\0') {
        g = (GLNode *) malloc (sizeof(GLNode));
        if (ch == '(') {
            g->tag = 1;
            g->val.sublist = CreateGL(s);
        } else if (ch == ')') {
            g = NULL;
        } else if (ch == '#') {
            g = NULL;
        } else {
            g->tag = 0;
            g->val.data = ch;
        }
    } else {
        g = NULL;
    }
    ch = * s ++;
    if (g != NULL) {
        if (ch == ',') {
            g->link = CreateGL(s);
        } else {
            g->link = NULL;
        }
    }
    return g;
}

//销毁广义表
void DestroyGL(GLNode * &g) {
    GLNode * g1, * g2;
    g1 = g->val.sublist;
    while (g1 != NULL) {
        if (g1->tag == 0) {
            g2 = g1->link;
            free(g1);
            g1 = g2;
        } else {
            g2 = g1->link;
            DestroyGL(g1);
            g1 = g2;
        }
    }
    free(g);
}

















////////////////测试数据//////////////////
/*
char str[20] = "(a,(b,c,d),(#))";
    char * s = str;
    GLNode * g;
    g = CreateGL(s);
    cout << "Length of g is " << GLLength(g) << endl;
    cout << "Depth of g is " <<  GLDepth(g) << endl;
    cout << "Display g: ";
    DispGL(g);
    DestroyGL(g);
    return 0;
*/