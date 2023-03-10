#include <iostream>

using namespace std;

typedef long long LL;

LL sum(int n) {
	LL sum = 0, fact = 1;
	for (int i = 1; i <= n; i ++) {
		fact *= i;
		sum += fact;
	}
	return sum;
}

int main() {
	cout << "Type in -1 to quit the program." << endl;
	bool flag = true;
	while (flag) {
		int n;
		cout << "n(between 3 and 20): ";
		cin >> n;
		if (n == -1) return 0;
		if (n < 3 || n > 20) {
			cout << "n is not between 3 and 20. Please retype in." << endl;
			continue;
		}
		cout << "1! + 2! + ...... + " << n << "! = " << sum(n) << endl;
	}
	
	return 0;
}
