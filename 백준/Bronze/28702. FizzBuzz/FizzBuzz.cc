#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string a, b, c; cin >> a >> b >> c;
	int result;

	if (isdigit(c.front()))
		result = stoi(c) + 1;

	else if (isdigit(b.front()))
		result = stoi(b) + 2;

	else if (isdigit(a.front()))
		result = stoi(a) + 3;

	if (result % 15 == 0)
		cout << "FizzBuzz";

	else if (result % 3 == 0)
		cout << "Fizz";

	else if (result % 5 == 0)
		cout << "Buzz";

	else
		cout << result;
}