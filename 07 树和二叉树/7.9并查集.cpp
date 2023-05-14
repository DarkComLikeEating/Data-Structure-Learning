typedef start node {
    int data;
    int rank;
    int parent;
} UFSTree;

//��ʼ�����鼯��
void MAKE_SET(UFSTree t[], int n) {
    int i;
    for (i = 1; i <= n; i ++) {
        t[i].data = i;
        t[i].rank = 0;
        t[i].parent = i;
    }
}

//����һ��Ԫ�������ļ���
int FIND_SET(UFSTree t[], int x) {
    if (x != t[x].parent) {
        return FIND_SET(t.t[x].parent);
    } else {
        return x;
    }
}

//����Ԫ�ظ��������ļ��ϵĺϲ�
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