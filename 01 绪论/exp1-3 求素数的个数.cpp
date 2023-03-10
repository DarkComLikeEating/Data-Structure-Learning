#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

typedef long long LL;

// ---Method 1---
bool prime1(LL n) {	
	for (LL i = 2; i < n; i ++) {
		if (n % i == 0) {
			return false;
		}
	}
	 
	return true;
}

void primeTime1(LL n) {
	clock_t t;
	LL sum = 0;
	t = clock();
	for (LL i = 2; i <= n; i ++) {
		if (prime1(i)) sum ++;
	}
	t = clock() - t;
	cout << "Method 1: " << endl;
	cout << "Result: The prime number of 2~" << n << " is " << sum << endl;
	printf("Time: %lf seconds\n", ((float)t) / CLOCKS_PER_SEC);
}

// ---Method 2---
bool prime2(LL n) {
	for (int i = 2; i <= (int)sqrt(n); i ++) {
		if (n % i == 0) 
			return false;
	}
	
	return true;
}

void primeTime2(LL n) {
	clock_t t;
	LL sum = 0;
	t = clock();
	for (int i = 2; i <= n; i ++) {
		if (prime2(i)) sum ++;
	}
	t = clock() - t;
	cout << "Method 2: " << endl;
	cout << "Result: The prime number of 2~" << n << " is " << sum << endl;
	printf("Time: %lf seconds\n", ((float)t) / CLOCKS_PER_SEC);
}

// ------------

int main() {
	cout << "Type -1 to quit the program.\n";
	bool flag = true;
	while (flag) {
		LL n;
		cout << "n(more than 10000): ";
		cin >> n;
		if (n == -1) return 0;
		if (n < 100000) {
			cout << "n is less than 100000. Please retype in." << endl;
			cout << endl;
			continue;
		}
		primeTime1(n);
		primeTime2(n);
		cout << endl;
	}
	
	return 0;
}
