#include <iostream>
#include "后缀表达式的计算.cpp"
#include "后缀表达式的转换.cpp"

using namespace std;

int main() {
    char exp[] = "1+1";
    char postexp[Maxsize];
    trans(exp, postexp);
    cout << "中缀表达式：" << exp << endl;
    cout << "后缀表达式：" << postexp << endl;
    cout << "表达式的值：" << ComputeValue(postexp) << endl;
    return 0;
}
