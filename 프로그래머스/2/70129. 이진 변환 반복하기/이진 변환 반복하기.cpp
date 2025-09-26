#include <string>
#include <vector>
#include <string>
using namespace std;

// 4  0
// 2  0
// 1  1
// 0

int cnt;

string i2b(int num) {
    string s = "";
    
    while (num) {
        s = to_string(num % 2) + s;
        num /= 2;
    }
    
    return s;
}

string transformation(string s) {
    string s_ = "";
        
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') s_ += s[i];
        else cnt++;
    }
    
    return i2b(s_.length());
}

vector<int> solution(string s) {
    vector<int> answer;
    int t = 0;
    cnt = 0;
    
    while (s != "1") {
        s = transformation(s);
        t++;
    }
    
    answer = {t, cnt};
    return answer;
}