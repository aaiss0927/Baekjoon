#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str; cin >> str;
    string bomb; cin >> bomb;
    string rest;

    for (char c : str) {
        rest += c;

        if (rest.length() >= bomb.length()) {
            string comp = rest.substr(rest.length() - bomb.length(), rest.length());

            if (comp == bomb) {
                int temp = bomb.length();

                while (temp--) {
                    rest.pop_back();
                }
            }
        }
    }

    if (rest.empty())
        cout << "FRULA";
    else
        cout << rest;
}