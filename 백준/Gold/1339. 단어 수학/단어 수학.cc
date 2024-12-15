#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> alphabet(26);
	vector<pair<int,char>> decoder(26);

	for (int i = 0; i < 26; i++)
		decoder[i].second = i + 'A';

	for (int i = 0; i < n; i++) {
		string str; cin >> str;

		for (int i = 0; i < str.length(); i++) {
			int exp = str.length() - i - 1;
			decoder[str[i] - 'A'].first += pow(10, exp);
		}
	}

	sort(decoder.rbegin(), decoder.rend());

	int result = 0;
	int value = 9;

	for (int i = 0; i < 26; i++) {
		if (decoder[i].first == 0)
			break;

		alphabet[decoder[i].second - 'A'] = value;
		result += decoder[i].first * value;
		value--;
	}
	
	cout << result;
}