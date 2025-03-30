#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> submit_1 = {1, 2, 3, 4, 5};
    vector<int> submit_2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> submit_3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> cnt(3, 0);
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == submit_1[i % submit_1.size()]) cnt[0]++;
        if (answers[i] == submit_2[i % submit_2.size()]) cnt[1]++;
        if (answers[i] == submit_3[i % submit_3.size()]) cnt[2]++;
    }
    
    int cnt_max = *max_element(cnt.begin(), cnt.end());
    
    for (int i = 0; i < cnt.size(); i++)
        if (cnt[i] == cnt_max) answer.push_back(i + 1);
    
    return answer;
}