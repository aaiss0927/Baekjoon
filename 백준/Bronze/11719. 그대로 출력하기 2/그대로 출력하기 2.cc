#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		string str;
		if (getline(cin, str))
			cout << str << '\n';
		else
			break;
	}
}