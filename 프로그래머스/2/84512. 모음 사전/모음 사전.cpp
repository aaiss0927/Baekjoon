#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> v;
vector<char> dict = {'A', 'E', 'I', 'O', 'U'};
int answer, temp;

// 0, 00, 000, 0000, 00000, 00001, 00002, ,,, 10000, ,,, 44444
void bt(string word, int cnt) {
    if (cnt > 5) return;
    
    temp++;
    string str = "";
    for (int i = 0; i < cnt; i++) str += dict[v[i]];
    if (word == str) answer = temp;
    
    for (int i = 0; i < 5; i++) {
        v.push_back(i);
        bt(word, cnt + 1);
        v.pop_back();
    }
}

int solution(string word) {
    temp = -1;
    bt(word, 0);
    return answer;
}

// 전체 가짓수: 5^5 => 백트래킹 가능
// 한번 쓴 단어 가능, 사전순이므로 bt(cur), i >= cur 조건 추가