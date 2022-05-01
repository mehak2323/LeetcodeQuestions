class Solution {
public:
    
    void recursiveNQueen(int col, int n, vector<vector<string>> &ans, vector<string> &board, vector<bool> &upleftdiag, vector<bool> &lowleftdiag, vector<bool> &leftcols){
        
        //base case, if all col filled
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        //For current col, traverse all rows to place Q
        for(int row=0; row<n; row++){
            
            //if hashes to find Q in directions of traversed area are unvisited
            if(upleftdiag[n-1 + col-row]==0 && lowleftdiag[row + col]==0 && leftcols[row]==0){
                
                //Visit current cell and mark hashes visited
                upleftdiag[n-1 + col-row] = lowleftdiag[row + col] = leftcols[row]= true;
                
                //recursion
                board[row][col]='Q';
                recursiveNQueen(col+1, n, ans, board, upleftdiag, lowleftdiag, leftcols);
                board[row][col]='.'; //backtrack
                
                //unvisit current cell and mark hashes unvisited
                upleftdiag[n-1 + col-row] = lowleftdiag[row + col] = leftcols[row]= false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        //make board
        string onerow(n,'.');
        vector<string> board(n, onerow);
        
        //Hashing structures to avoid traversing directions to find Q
        //all false/ unmarked
        vector<bool> upleftdiag(2*n - 1) , lowleftdiag(2*n - 1), leftcols(n); 
        
        recursiveNQueen(0, n, ans, board, upleftdiag, lowleftdiag, leftcols);
        
        return ans;
    }
};

//Explanation of these hashes and sizes in video
//link: https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/

//TC: O(n^2) //would be n^3 if we check all directions without hashes
//SC: O(n^2) //the board (n^2) + hashes (n) + recursive stack (n)