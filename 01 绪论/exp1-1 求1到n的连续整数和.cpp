#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

typedef long long ll;

// Method 1
ll add1(ll n) {
	ll i, sum = 0;
	for (int i = 1; i <= n; i ++) sum += i;
	return sum;
}

void addTime1(ll n) {
	clock_t t;
	ll sum;
	t = clock();
	sum = add1(n);
	t = clock() - t;
	cout << "Methon 1:\n";
	cout << "Result: sum of 1~" << n << ": " << sum << endl;
	printf("Time: %llf seconds\n", ((double)t) / CLOCKS_PER_SEC);
}

// Method 2
ll add2(ll n) {
	return n * (1 + n) / 2;
}

void addTime2(ll n) {
	clock_t t;
	ll sum;
	t = clock();
	sum = add2(n);
	t = clock() - t;
	cout << "Method 2:\n";
	cout << "Result: sum of 1~" << n << ": " << sum << endl;
	printf("Time: %llf seconds\n", ((double)t) / CLOCKS_PER_SEC);
}

int main() {
	cout << "Type in -1 to quit the program.\n";
	bool flag = true;
	while (flag) {
		ll n;
		cout << "n(more than 1000000): ";
		cin >> n;
		if (n == -1) return 0;
		if (n < 1000000) {
			cout << "n is not more than 1000000. Please retype in." << endl;
			continue;
		}
		addTime1(n);
		addTime2(n);		
	}
	
	return 0;
}
