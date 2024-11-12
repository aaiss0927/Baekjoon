#include <iostream>
#include <string>
using namespace std;

int rev(string num) {
	string result = "";

	for (char c : num)
		result = c + result;

	return atoi(result.c_str());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string x, y; cin >> x >> y;

	int rev_x = rev(x); 
	int rev_y = rev(y);
	string sum = to_string(rev_x + rev_y);

	cout << rev(sum);
}