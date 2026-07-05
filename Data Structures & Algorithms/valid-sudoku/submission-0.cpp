class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                char num = board[r][c];
                if(num=='.')
                continue;
                string row="row"+to_string(r)+num;
                string col="col"+to_string(c)+num;
                string board="box"+to_string((r/3)*3+(c/3))+num;


                if(seen.count(row)|| seen.count(col)|| seen.count(board))
                return false;

                seen.insert(row);
                seen.insert(col);
                seen.insert(board);
            }
        }
        return true;
    }
};
