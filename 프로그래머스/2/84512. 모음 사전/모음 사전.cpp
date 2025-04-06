#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<char> vowel = {'A', 'E', 'I', 'O', 'U'};
vector<string> words;
vector<char> v;

void bt(int len) {
    if (v.size() == len) {
        string str = "";
        
        for (int i = 0; i < len; i++)
            str += v[i];
        
        words.push_back(str);
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        v.push_back(vowel[i]);
        bt(len);
        v.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    
    for (int i = 1; i <= 5; i++)
        bt(i);
    
    sort(words.begin(), words.end());
    answer = lower_bound(words.begin(), words.end(), word) - words.begin();
    answer++;
    return answer;
}