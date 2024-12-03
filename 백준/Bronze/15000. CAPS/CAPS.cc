#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str; cin >> str;

	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);

	cout << str;
}