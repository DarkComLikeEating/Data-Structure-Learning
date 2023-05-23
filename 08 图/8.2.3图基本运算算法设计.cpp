#include <iostream>
using namespace std;
#define MAXV 100
#define INF 32767
#define InfoType char

//邻接矩阵
typedef struct {
    int no;
    InfoType info;
} VertexType;

typedef struct {
    int edges[MAXV][MAXV];
    int n, e;
    VertexType vexs[MAXV];
} MatGraph;

//邻接表
typedef struct ANode {
    int adjvex;
    struct ANode * nextarc;
    int weight;
} ArcNode;

typedef struct Vnode {
    InfoType info;
    ArcNode * firstarc;
} VNode;

typedef struct {
    VNode adjlist[MAXV];
    int n, e;
} AdjGraph;

//创建图
void CreateAdj(AdjGraph * &G, int A[MAXV][MAXV], int n, int e) {
    int i, j;
    ArcNode * p;
    G = (AdjGraph * ) malloc (sizeof(AdjGraph));
    for (i = 0; i < n; i ++) {
        G->adjlist[i].firstarc = NULL;
    }
    for (i = 0; i < n; i ++) {
        for (j = n - 1; j >= 0; j --) {
            if (A[i][j] != 0 && A[i][j] != INF) {
                p = (ArcNode * ) malloc (sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n; 
    G->e = e;
}

//输出图
void DispAdj(AdjGraph * G) {
    int i;
    ArcNode * p;
    for (i = 0; i < G->n; i ++) {
        printf("%3d: ", i);
        while (p != NULL) {
            printf("%3d[%d]->", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("^\n");
    }
}

//销毁图
void DestroyAdj(AdjGraph * &G) {
    int i; 
    ArcNode * pre, * p;
    for (i = 0; i < G->n; i ++) {
        pre = G->adjlist[i].firstarc;
        if (pre != NULL) {
            p = pre->nextarc;
            while (p != NULL) {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}