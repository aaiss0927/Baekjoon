#include <iostream>
#include <vector>
using namespace std;

int n;
vector<string> words;
bool is_erased[50];

bool is_prefix(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    
    if (len1 > len2) return false;
    
    for (int i = 0; i < len1; i++)
        if (word1[i] != word2[i]) return false;
        
    return true;
}

// 시간복잡도
// n개에 대해 words[i]가 words[j]의 prefix인지 검사 -> n * len_max (50*50)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        string word; cin >> word;
        words.push_back(word);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_erased[j] || i == j) continue;
            
            if (is_prefix(words[i], words[j])) {
                is_erased[i] = true;
                cnt++;
                break;
            }
        }
    }
    
    cout << n - cnt;
}