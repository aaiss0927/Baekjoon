#include <iostream>
#include <string>
using namespace std;

string get_reverse(string s) {
	string result = "";

	for (int i = 0; i < s.length(); i++) {
		result = s[i] + result;
	}

	return result;
}

int main() {
	string a, b; cin >> a >> b;
	a = get_reverse(a);
	b = get_reverse(b);
	int len_a = a.length();
	int len_b = b.length();
	int len = max(len_a, len_b);
	
	if (len_a < len_b) {
		for (int i = 0; i < len_b - len_a; i++) {
			a += '0';
		}
	}

	else {
		for (int i = 0; i < len_a - len_b; i++) {
			b += '0';
		}
	}

	string result = "";
	int carry = 0;
	for (int i = 0; i < len; i++) {
		int n = (a[i] - '0') + (b[i] - '0') + carry;
		carry = n / 10;
		n %= 10;
		result += (n + '0');
	}

	if (carry) {
		result += '1';
	}

	while (result[result.length() - 1] == '0') {
		result.pop_back();
	}

	result = get_reverse(result);
	cout << result;
}