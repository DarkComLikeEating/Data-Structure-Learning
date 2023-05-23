typedef struct {
    int u;
    int v;
    int w;
} Edge;

void Kruskal(MatGraph g) {
    int i, j, u1, v1, sn1, sn2, k;
    int vset[MAXV];
    Edge E[MaxSize];
    k = 0;
    for (i = 0; i < g.n; i ++) {
        for (j = 0; j < i; j ++) {
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
                E[k].u = i;
                E[k].v = j;
                E[k].w = g.edges[i][j];
                k ++;
            }
        }
    }
    InsertSort(E, g.e);
    for (i = 0; i < g.n; i ++) {
        vset[i] = i;
    }
    k = 1;
    j = 0;
    while (k < g.n) {
        u1 = E[j].u;
        v1 = E[j].v;
        sn1 = vset[u1];
        sn2 = vset[v1];
        if (sn1 != sn2) {
            printf("(%d,%d):%d\n", u1, v1, E[j].w);
            k ++;
            for (i = 0; i <g.n; i ++) {
                if (vset[i] == sn2) {
                    vset[i] - sn1;
                }
            }
        }
        j ++;
    }
}

//改进的Kruskal算法
void Kruskal2(MatGraph g) {
    int i, j, k, u1, v1, sn1, sn2;
    USFTree t[MaxSize];
    Edge E[MaxSize];
    k = 1;
    for (i = 0; i < g.n; i ++) {
        for (j = 0; j <= i; j ++) {
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
                E[k].u = i;
                E[k].v = j;
                E[k].w = g.edges[i][j];
                k ++;
            }
        }
    }
    HeapSort(E, g.e);
    MAKE_SET(E, g.e);
    k = 1;
    j = 1;
    while (k < g.n) {
        u1 = E[j].u;
        v1 = E[j].v;
        sn1 = FIND_SET(t, u1);
        sn2 = FIND_SET(t, v1);
        if (sn1 != sn2) {
            printf("(%d,%d):%d\n", u1, v1, E[j].w);
            k ++;
            UNION(t, u1, v1);
        }
        j ++;
    }
}