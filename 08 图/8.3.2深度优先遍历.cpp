int visited[MAX];

void DFS(AdjGraph * G, int v) {
    ArcNode * p;
    visited[v] = 1;
    printf("%d", v);
    p = G->adjlist[v].firstarc;
    while (p != NULL) {
        if (visited[p->adjvex] == 0) {
            DFS(G, p->adjvex);
        }
        p = p->nextarc;
    }
}