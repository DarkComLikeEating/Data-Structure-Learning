#include <iostream>

using namespace std;

const int Maxsize = 100;

typedef struct {
    int i;
    int j;
} Box;

typedef struct {
    Box data[Maxsize];
    int length;
} Pathtype;

void mgpath(int xi, int yi, int xe, int ye, Pathtype path) {
    int di, k, i, j;
    if (xi == xe && yi == ye) {
        path.data[path.length].i = xi;
        path.data[path.length].j = yi;
        path.length ++;
        cout << "ÃÔ¹¬Â·¾¶" << ++ count
    }
}