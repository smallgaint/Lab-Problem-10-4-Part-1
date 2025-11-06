#include <iostream>

using namespace std;

const int DIGIT_COUNT = 16;

bool isNumeric(string s);
bool isCorrectLength(string s);
bool isCardValid(int digits[], int size);

int main(void) {
	string card_number;
	int digits[DIGIT_COUNT];

	while (true) {
		cout << "Enter 16-digit credit card # or Q to quit: ";
		cin >> card_number;

		if (card_number == "q" || card_number == "Q") {
			return 0;
		} else if (!isNumeric(card_number)) {
			cout << "Error - card number must contain only digits." << endl;
			continue;
		} else if (!isCorrectLength(card_number)) {
			cout << "Error - card number must contain 16 digits." << endl;
			continue;
		}

		for (int i = 0; i < DIGIT_COUNT; i++) {
			digits[i] = card_number[i] - '0';
		}

		if (isCardValid(digits, DIGIT_COUNT)) {
			cout << "Card is valid." << endl;
		}
		else {
			cout << "Card is not valid." << endl;
		}
	}
	cout << endl;
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

bool isNumeric(string s) {
	for (char c : s) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

bool isCorrectLength(string s) {
	return s.length() == DIGIT_COUNT;
}