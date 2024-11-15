#include <iostream>
#include <string>
#include <vector>
using namespace std;

string get_reverse(string str) {
	string result = "";
	
	for (char c : str)
		result = c + result;

	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	cin.ignore();

	while (T--) {
		string str;
		getline(cin, str);

		vector<int> ws_idx;

		for (int i = 0; i < str.length(); i++)
			if (str[i] == ' ')
				ws_idx.push_back(i);

		if (ws_idx.empty()) {
			cout << get_reverse(str) << '\n';
			continue;
		}

		vector<string> str_arr;

		str_arr.push_back(str.substr(0, ws_idx[0]));
		for (int i = 1; i < ws_idx.size(); i++)
			str_arr.push_back(str.substr(ws_idx[i - 1] + 1, ws_idx[i] - ws_idx[i - 1] - 1));
		str_arr.push_back(str.substr(ws_idx[ws_idx.size() - 1] + 1, str.length() - ws_idx[ws_idx.size() - 1] - 1));

		for (int i = 0; i < str_arr.size(); i++) 
			cout << get_reverse(str_arr[i]) << ' ';
		cout << '\n';
	}
}