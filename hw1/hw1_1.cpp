#include <iostream>

using namespace std;

void mySort(int arr[], int n)
{

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < (n - i) - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[] = { 3, 1, 2, 5, 6, 7,2,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	mySort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}