#include <iostream>
using namespace std;

// A simple print function
void print(int* input) {
	for (int i = 0; i < 5; i++)
        cout << input[i] << " ";
    cout << endl;
}

int partition(int* input, int p, int r) {
    int pivot = input[r];
    while ( p < r ) {
        while (input[p] <= pivot)
            p++;
        while (input[r] > pivot)
            r--;
      	// now we have input[p] > pivot && input[r] <= pivot
		// we need to swap values at p and r if p < r
        if (p < r) {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }
    return r;
}

void quick_sort(int* input, int p, int r) {
    if (p == r) return;
    int j = partition(input, p, r);
    quick_sort(input, p, j - 1);
    quick_sort(input, j + 1, r);
	return;
}

int main() {
    int A1[] = { 100, 400, 300, 500, 200 };
	print(A1);
    quick_sort(A1, 0, 4);
	print(A1);
	
	int A2[] = { 100, 400, 100, 200, 200 };
	print(A2);
	quick_sort(A2, 0, 4);
	print(A2);
}

