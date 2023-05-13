#include <iostream>

using namespace std;

const int Maxsize = 10;

void Hanoi1(int n, char X, char Y, char Z) {
    if (n == 1) {
        cout << "\t����" << n << "����Ƭ��" << X << "�ƶ���" << Y << endl;
    } else {
        Hanoi1(n - 1, X, Z, Y);
        cout << "\t����" << n << "����Ƭ��" << X << "�ƶ���" << Y << endl;
        Hanoi1(n - 1, Y, X, Z);
    }
}
