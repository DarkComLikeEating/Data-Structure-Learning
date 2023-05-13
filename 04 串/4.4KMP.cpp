#include "Ë³Ðò´®.cpp"
#include <iostream>

using namespace std;

void GetNext(SqString t, int next[]) {
    int j = 0, k = -1;
    next[0] = -1;
    while (j < t.length - 1) {
        if (k == -1 || t.data[j] == t.data[k]) {
            j ++;
            k ++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

int KMP(SqString s, SqString t) {
    int next[Maxsize], i = 0, j = 0;
    GetNext(t, next);
    // for (int i = 0; i < t.length; i ++) cout << next[i] << " ";
    // cout << endl;
    while (i < s.length && j < t.length) {
        if (j == -1 || s.data[i] == t.data[j]) {
            i ++;
            j ++;
        } else {
            j = next[j];
        }
    }
    if (j >= t.length) {
        return (i - t.length);
    } else {
        return -1;
    }
}