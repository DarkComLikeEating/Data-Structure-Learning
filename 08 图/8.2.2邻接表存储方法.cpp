#define MAXV 100

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