#include <iostream>

using namespace std;

int Fib1(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return (Fib1(n - 1) + Fib1(n - 2));
    }
}

int Fib2(int n) {
    int a = 1, b = 1, i, s;
    if (n == 1 || n == 2) {
        return 1;
    } else {
        for (int i = 3; i <= n; i ++) {
            s = a + b;
            a = b;
            b = s;
        }
        return s;
    }
}