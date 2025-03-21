#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto cmd : commands) {
        int a = cmd[0] - 1;
        int b = cmd[1] - 1;
        int c = cmd[2] - 1;
        
        vector<int> temp;
        
        for (int i = a; i <= b; i++)
            temp.push_back(array[i]);
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[c]);
    }
    
    return answer;
}

// cmd(50) * 배열 복사(100) * 정렬(nlogn)