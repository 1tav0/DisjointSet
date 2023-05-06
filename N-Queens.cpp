class Solution {
public: 
    bool isSafe(int row, int col, vector<string>& board, int n){
        int originalRow = row;
        int originalCol = col;
        //upper left diagonal
        while(col>=0 && row>=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = originalRow;
        col = originalCol;  
        //left
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = originalRow;
        //lower left diagonal
        col = originalCol;
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
        }
        return true;
    }
    void helper(int col, vector<string>& board, vector<vector<string>>& ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int r=0; r<n; r++){
            if(isSafe(r,col,board,n)){
                board[r][col] = 'Q';
                helper(col+1,board,ans,n);
                board[r][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        // vector<vector<string>> grid(n, vector<string>(n,'.'));
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        vector<vector<string>> ans;
        helper(0,board,ans,n);
        return ans;
    }
};