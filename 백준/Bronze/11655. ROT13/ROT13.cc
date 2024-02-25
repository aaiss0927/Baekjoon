#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            str[i] = ((str[i] - 'A') + 13) % 26 + 'A';
        }

        else if (islower(str[i])) {
            str[i] = ((str[i] - 'a') + 13) % 26 + 'a';
        }
    }

    cout << str;
}