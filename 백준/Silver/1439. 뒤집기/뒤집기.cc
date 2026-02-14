#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	string str; cin >> str;
	int len = str.length();
	int cont[2] = { 0, 0 };
	char prev = str[0];
	
	for (int i = 1; i < len; i++) {
		if (str[i] != prev)
			cont[prev - '0']++;

		prev = str[i];
	}
	cont[prev - '0']++;

	cout << *min_element(cont, cont + 2);
}