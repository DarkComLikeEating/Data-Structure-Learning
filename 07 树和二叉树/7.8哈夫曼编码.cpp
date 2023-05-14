typedef struct {
    char cd[N];
    int start;
} HCode;

void CreateHCode(HTNode ht[], HCode hcd[], int n0) {
    int i, f, c;
    HCode hc;
    for (i = 0; i < n0; i ++) {
        hc.start = n0;
        c = i;
        f = ht[i].parent;
        while (f != -1) {
            if (ht[f].lchild == c) {
                hc.cd[hc.start --] = '0';
            } else {
                hc.cd[hc.start --] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        hc.start ++;
        hcd[i] = hc;
    }
}