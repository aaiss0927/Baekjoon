#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; cin >> N >> M;
    map<int, string> collection_key_num;
    map<string, int> collection_key_name;

    for (int i = 1; i <= N; i++) {
        string name; cin >> name;
        collection_key_num.insert({ i, name });
        collection_key_name.insert({ name, i });
    }

    for (int i = 0; i < M; i++) {
        string input; cin >> input;

        if (isdigit(input.front())) {
            cout << collection_key_num.find(stoi(input))->second << '\n';
        }

        else {
            cout << collection_key_name.find(input)->second << '\n';
        }
    }
}