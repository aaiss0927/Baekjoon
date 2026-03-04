#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

void ms_printer(multiset<int> ms) {
    for (auto _ : ms) cout << _ << ' ';
    cout << '\n';
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    
    for (const auto& op : operations) {
        char cmd; int num;
        cmd = op[0];
        num = stoi(op.substr(2, op.length() - 2));
        
        if (cmd == 'I') ms.insert(num);
        
        else {
            if (ms.empty()) continue;
            
            if (num == 1) ms.erase(--ms.end());
            else ms.erase(ms.begin());
        }
    }
    
    if (ms.empty()) return {0, 0};
    
    answer = {*(--ms.end()), *ms.begin()};
    return answer;
}