#include <iostream>
#include "��׺���ʽ�ļ���.cpp"
#include "��׺���ʽ��ת��.cpp"

using namespace std;

int main() {
    char exp[] = "1+1";
    char postexp[Maxsize];
    trans(exp, postexp);
    cout << "��׺���ʽ��" << exp << endl;
    cout << "��׺���ʽ��" << postexp << endl;
    cout << "���ʽ��ֵ��" << ComputeValue(postexp) << endl;
    return 0;
}
