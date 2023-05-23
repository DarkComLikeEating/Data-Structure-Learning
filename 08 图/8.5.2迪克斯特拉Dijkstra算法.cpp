void Dijkstra(MatGraph g, int v) {
    int dist[MAXV], path[MAXV];
    int S[MAXV];
    int MINdis, i, j, u;
    for (i = 0; i < g.n; i ++) {
        dist[i] = g.edges[v][i];
        S[i] = 0;
        if (g.edges[v][i] < INF) {
            path[i] = v;
        } else {
            path[i] = -1;
        }
    }
    S[v] = 1;
    path[v] = 0;
    for (i = 0; i < g.n - 1; i ++) {
        MINdis = INF;
        for (j = 0; j < g.n; j ++) {
            if (S[j] == 0 && dist[j] < MINdis) {
                u = j;
                MINdis = dist[j];
            }
        }
        S[u] = 1;
        for (j = 0; j < g.n; j ++) {
            if (S[j] == 0) {
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][i] < dist[j]) {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
            }
        }
    }
    Dispath(g, dist, path, S, v);
}

void Dispath(MatGraph g, int dist[], int path[], int S[], int v) {
    int i, j, k;
    int apath[MAXV], d;
    for (i = 0; i < g.n; i ++) {
        if (S[i] == 1 && i != v) {
            printf("从顶点%d到顶点%d的路径长度为:%d\t路径为:", v, i, dist[i]);
            d = 0;
            apath[d] = i;
            k = path[i];
            if (k == -1) {
                printf("无路径\n");
            } else {
                while (k != v) {
                    d ++;
                    apath[d] = k;
                    k = path[k];
                }
                d ++;
                apath[d] = v;
                printf("%d", apath[d]);
                for (j = d - 1; j >= 0; j --) {
                    printf(",%d", apath[j]);
                }
                printf("\n");
            }
        }
    }
}