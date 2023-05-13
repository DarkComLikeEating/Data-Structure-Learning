#include <iostream>
#include <algorithm>

using namespace std;

int a[10] = {9, 3, 5, 2, 7, 8, 0, 1, 4, 6};

void quick_sort(int a[], int l, int r) {
	if (l >= r) return;
	
	int i = l - 1, j = r + 1, mid = l + r >> 1;
	while (i < j) {
		do i ++; while (a[i] < a[mid]);
		do j --; while (a[j] > a[mid]);
		if (i < j) swap(a[i], a[j]);
	}
	
	quick_sort(a, l, j); quick_sort(a, j + 1, r);
}

int main() {
	quick_sort(a, 0, 9);
	for (int i = 0; i < 10; i ++) cout << a[i] << " ";
	
	return 0;
}
