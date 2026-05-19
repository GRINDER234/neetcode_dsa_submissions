class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                char ch = board[i][j];
                if(board[i][j] == '.') continue;
                
                int b_idx = (i / 3) * 3 + (j / 3);
                if(rows[i].find(ch) != rows[i].end() || cols[j].find(ch) != cols[j].end() || boxes[b_idx].find(ch) != boxes[b_idx].end()){
                    return false;
                }

                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[b_idx].insert(ch);
            }
        }

        return true;
    }
};
