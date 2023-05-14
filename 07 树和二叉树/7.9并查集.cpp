typedef start node {
    int data;
    int rank;
    int parent;
} UFSTree;

//初始化并查集树
void MAKE_SET(UFSTree t[], int n) {
    int i;
    for (i = 1; i <= n; i ++) {
        t[i].data = i;
        t[i].rank = 0;
        t[i].parent = i;
    }
}

//查找一个元素所属的集合
int FIND_SET(UFSTree t[], int x) {
    if (x != t[x].parent) {
        return FIND_SET(t.t[x].parent);
    } else {
        return x;
    }
}

//两个元素各自所属的集合的合并
void UNION(UFSTree t[], int x, int y) {
    x = FIND_SET(t, x);
    y = FIND_SET(t, y);
    if (t[x].rank > t[y].rank) {
        t[y].parent = x;
    } else {
        t[x].parent = y;
        if (t[x].rank == t[y].rank) {
            t[y].rank ++;
        }
    }
}