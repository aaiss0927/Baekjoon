#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	string str; cin >> str;
	int result = 0;

	for (int i = 0; i < str.length(); i++) {
		int num;
		
		if (isdigit(str[i]))
			num = str[i] - '0';
		else
			num = (str[i] - 'A') + 10;

		result += num * pow(16, str.length() - i - 1);
	}

	cout << result;
}