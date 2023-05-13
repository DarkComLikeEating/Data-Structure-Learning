#include <iostream>
#include "Ë³Ðò´®.cpp"

using namespace std;

void GetNextVal(SqString t, int nextval[]) {
    int j = 0, k = -1;
    nextval[0] = -1;
    while (j < t.length) {
        if (k == -1 || t.data[j] == t.data[k]) {
            j ++;
            k ++;
            if (t.data[j] != t.data[k]) {
                nextval[j] = k;
            } else {
                nextval[j] = nextval[k];
            }
        } else {
            k = nextval[k];
        }
    }
}

int KMPIndex1(SqString s, SqString t) {
    int nextval[Maxsize], i = 0, j = 0;
    GetNextVal(t, nextval);
    while (i < s.length && j < t.length) {
        if (j == -1 || s.data[i] == t.data[j]) {
            i ++;
            j ++;
        } else {
            j = nextval[j];
        }
    }
    if (j >= t.length) {
        return (i - t.length);
    } else {
        return -1;
    }
}