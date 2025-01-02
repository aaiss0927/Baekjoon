#include <iostream>
using namespace std;

string bin2oct(string bin) {
    string oct = "";
    string temp = "";

    for (int i = 0; i < bin.length(); i += 3) {
        int num = (bin[i] - '0') * 4 +
                  (bin[i + 1] - '0') * 2 +
                  (bin[i + 2] - '0');

        oct += char(num + '0');
    }

    return oct;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string bin; cin >> bin;

    while (bin.length() % 3 != 0)
        bin = '0' + bin;

    string oct = bin2oct(bin);

    int start_idx = 0;

    while (start_idx < oct.length() - 1 && oct[start_idx] == '0')
        start_idx++;

    cout << oct.substr(start_idx);
}