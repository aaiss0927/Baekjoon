#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int num = 0;
    bool flag = false;
    
    for (int i = 1; i < words.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (words[i] == words[j]) {
                flag = true;
                num = i;
                break;
            }
        }
        
        if (flag) break;
    }
    
    if (!flag) {
        for (int i = 1; i < words.size(); i++) {
            if (words[i].front() != words[i - 1].back()) {
                flag = true;
                num = i;
                break;
            }
        }
    }
    
    if (!flag) {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    else {
        int first = (num + 1) % n ? (num + 1) % n : (num + 1) % n + n;
        int second = (num / n) + 1;
        
        answer.push_back(first);
        answer.push_back(second);
    }

    return answer;
}