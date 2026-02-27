#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<vector<int>> board;
// board = {{num, rec_cnt, created_at}}

bool cmp(vector<int> v1, vector<int> v2) {
    if (v1[1] == v2[1])
        return v1[2] > v2[2];
    
    return (v1[1] > v2[1]);
}

int board_idx(int num) {
    for (int i = 0; i < board.size(); i++) {
        if (board[i][0] == num) return i;
    }
    return -1;
}

int main() {
    int n, cnt; cin >> n >> cnt;
    int idx = 0;
    
    for (int i = 0; i < cnt; i++) {
        int num; cin >> num;
        
        if (board_idx(num) != -1)
            board[board_idx(num)][1]++;
        
        else {
            if (board.size() >= n) {
                sort(board.begin(), board.end(), cmp);
                board.pop_back();
            }
            
            board.push_back({num, 1, idx});
            idx++;
        }
    }
    
    sort(board.begin(), board.end());
    
    for (auto b : board)
        cout << b[0] << ' ';
}