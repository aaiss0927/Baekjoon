#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
        
    for (int h = citations.size(); h > 0; h--) {
        if (citations[citations.size() - h] >= h) {
            answer = h;
            break;
        }
    }
    
    return answer;
}
// 0 2 3 10000
// 1 2 50 100 10000

// h = 5
// i = 5, 1 >= 5 x
// i = 4, 2 >= 4 x
// i = 3, 50 >= 3 o