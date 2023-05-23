void BFS(AdjGraph * G, int v) {
    int w, i;
    ArcNode * p;
    SqQueue * qu;
    InitQueue(qu);
    int visited[MAXV];
    for (i = 0; i < G->n; i ++) visited[i] = 0;
    printf("%2d", v);
    visited[v] = 1;
    EnQueue(qu, v);
    while (!QueueEmpty(qu)) {
        DeQueue(qu, w);
        p = G->adjlist[w].firstarc;
        while (p != NULL) {
            if (visited[p->adjvex] == 0) {
                printf("%2d", p->adjvex);
                visited[p->adjvex] = 1;
                EnQueue(qu, p->adjvex);
            }
            p = p->nextarc;
        }
    }
    printf("\n");
}