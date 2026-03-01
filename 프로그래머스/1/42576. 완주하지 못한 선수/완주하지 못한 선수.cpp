#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> record;
    
    for (auto const& p : participant)
        record[p]++;
    
    for (auto const& c : completion)
        record[c]--;
    
    for (auto const& r : record) {
        if (r.second == 1) {
            answer = r.first;
            break;
        }
    }
    
    return answer;
}

// 1 <= n <= 10^5