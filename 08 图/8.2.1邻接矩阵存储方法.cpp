#define MAXV 100
#define INF 32767
typedef struct {
    int no;
    InfoType info;
} VertexType;

typedef struct {
    int edges[MAXV][MAXV];
    int n, e;
    VertexType vexs[MAXV];
} MatGraph;