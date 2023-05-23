void Prim(MatGraph g, int v) {
    int lowcost[MAXV];
    int MIN;
    int closest[MAXV], i, j, k;
    for (i = 0; i < g.n; i ++) {
        lowcost[i] = g.edges[v][i];
        closest[i] = v;
    }
    for (i = 1; i < g.n; i ++) {
        MIN = INF;
        for (j = 0; j < g.n; j ++) {
            if (lowcost[j] != 0 && lowcost[j] < MIN) {
                MIN = lowcost[j];
                k = j;
            }
        }
        printf("±ß(%d,%d)È¨Îª: %d\n", closest[k], k, MIN);
        lowcost[k] = 0;
        for (j = 0; j < g.n; j ++) {
            if (lowcost[j] != g.n; j ++) {
                lowcost[j] = g.edges[k][j];
                closest[j] = k;
            }
        }
    }
}