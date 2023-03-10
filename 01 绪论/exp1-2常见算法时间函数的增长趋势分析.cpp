#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

double log2(double n) {
	return log10(n) / log10(2);
}

LL exponent(int n) {
	LL s = 1;
	for (int i = 1; i <= n; i ++) s *= i;
	return s;
}

LL factorial(int n) {
	LL s = 1;
	for (int i = 1; i <= n; i ++) s *= i;
	return s;
}

void fun(int n) {
	cout << "log2(n) sqrt(n)  n	nlog2(n)  n^2      n^3      2^n            n!" << endl;
	cout << "=====================================================================" << endl;
	for (int i = 1; i <= n; i ++) {
		printf("%5.2llf\t", log2(double(i)));
		printf("%5.2llf\t", sqrt(i));
		printf("%2d\t", i);
		printf("%7.2llf\t", i * log2(double (i)));
		printf("%5d\t", i * i);
		printf("%7d\t", i * i * i);
		printf("%8d\t", exponent(i));
		printf("%10d\n", factorial(i));
	}
}

int main() {
	int n = 10;
	fun(n);
	return 0;
}


