#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> term;
    int n = progresses.size();
    
    for (int i = 0; i < n; i++)
        term.push_back(ceil(double(100 - progresses[i]) / speeds[i]));
    
    int cur = term[0];
    int cnt = 1;
    
    for (int i = 1; i < n; i++) {        
        if (term[i] <= cur)
            cnt++;
        
        else {
            answer.push_back(cnt);
            cur = term[i];
            cnt = 1;
        }
    }
    
    answer.push_back(cnt);
    
    return answer;
}