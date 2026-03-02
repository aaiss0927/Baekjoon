#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> hash_set(phone_book.begin(), phone_book.end());

    for (const string& number : phone_book) {
        string prefix = "";
        
        for (int i = 0; i < (int)number.size() - 1; i++) {
            prefix += number[i];
            
            if (hash_set.find(prefix) != hash_set.end()) return false;
        }
    }

    return true;
}