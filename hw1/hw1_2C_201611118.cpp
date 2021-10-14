#include <iostream>

using namespace std;


int count_1 = 1;
unsigned int func(int n) {
	
	if (n <= 1)
		return 1;

	else
		
		for (int i = 1; i < n+1; i++) {
			if (i % 2 == 0)
				count_1 = count_1 * i;
		}
	return count_1;
}

int main() {
	cout << func(20) << endl;

	return 0;
}
