#include <iostream>

using namespace std;

bool isCardValid(int digits[], int size);

int main(void) {
	int card_number;
	const int DIGIT_COUNT = 8;
	int digits[DIGIT_COUNT];

	while (true) {
		cout << "Enter 8-digit credit card # or Q to quit: ";
		cin >> card_number;

		if(cin.fail()) {
			return 0;
		}

		for (int i = DIGIT_COUNT - 1; i >= 0; i--) {
				digits[i] = card_number % 10;
				card_number /= 10;
		}

		if (isCardValid(digits, DIGIT_COUNT)) {
			cout << "Card is valid." << endl;
		}
		else {
			cout << "Card is not valid." << endl;
		}
	}
}

bool isCardValid(int digits[], int size) {
	int varify1 = 0, varify2 = 0;
	for (int i = 0; i < size; i++) {
		if (i % 2 != 0) {
			varify1 += digits[i];
		}
		else {
			int doubled = digits[i] * 2;
			varify2 += (doubled / 10) + (doubled % 10);
		}
	}
	return (varify1 + varify2) % 10 == 0;

}