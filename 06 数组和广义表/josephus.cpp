#include <iostream>

using namespace std;

const int Maxsize = 100;
//n个人，循环报数到m的出列
void josephus(int n, int m) {
    int p[Maxsize];
    int t;
    for (int i = 0; i < n; i ++) {
        p[i] = i + 1;
    }
    t = 0;
    cout << "出场顺序：";
    for (int i = n; i >= 1; i --) {
        t = (t + m - 1) % i;
        cout << p[t] << " ";
        for (int j = t + 1; j <= i - 1; j ++) {
            p[j - 1] = p[j];
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    n = 5, m = 3;
    josephus(5, 3);
    return 0;
}