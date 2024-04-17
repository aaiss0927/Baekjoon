#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	int b;
	cin >> n >> b;
	stack<char> ans;

	while (n != 0) {
		long long temp = n % b;

		if (temp >= 0 && temp <= 9) {
			ans.push(temp + '0');
		}

		else {
			ans.push((temp - 10) + 'A');
		}
		
		n /= b;
	}

	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
}