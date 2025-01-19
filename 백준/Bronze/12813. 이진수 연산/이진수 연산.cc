#include <iostream>
using namespace std;

string op_and(string a, string b) {
	string result = "";

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '1' && b[i] == '1')
			result += '1';
		else
			result += '0';
	}

	return result;
}

string op_or(string a, string b) {
	string result = "";

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '0' && b[i] == '0')
			result += '0';
		else
			result += '1';
	}

	return result;
}

string op_xor(string a, string b) {
	string result = "";

	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i])
			result += '1';
		else
			result += '0';
	}

	return result;
}

string op_not(string a) {
	string result = "";

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '0')
			result += '1';
		else
			result += '0';
	}

	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string A, B; cin >> A >> B;

	cout << op_and(A, B) << '\n';
	cout << op_or(A, B) << '\n';
	cout << op_xor(A, B) << '\n';
	cout << op_not(A) << '\n';
	cout << op_not(B);
}