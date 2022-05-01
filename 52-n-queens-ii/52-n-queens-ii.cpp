class Solution {
public:
    
    void recursiveNQueen(int col, int &ans, int &n, vector<bool> &upleftdiag, vector<bool> &lowleftdiag, vector<bool> &cols){
        
        //base case, if all col filled
        if(col==n){
            ans++;
            return;
        }
        
        //For current col, traverse all rows to place Q
        for(int row=0; row<n; row++){
            
            //if hashes to find Q in directions of traversed area are unvisited
            if(upleftdiag[n-1 + col-row]==0 && lowleftdiag[row + col]==0 && cols[row]==0){
                
                //Visit current cell and mark hashes visited
                upleftdiag[n-1 + col-row] = lowleftdiag[row + col] = cols[row]= true;
                
                //recursion
                recursiveNQueen(col+1, ans, n, upleftdiag, lowleftdiag, cols);
                
                //unvisit current cell and mark hashes unvisited
                upleftdiag[n-1 + col-row] = lowleftdiag[row + col] = cols[row]= false;
            }
        }
    }
    
    int totalNQueens(int n) {
        
        int ans=0;
        
        //Hashing structures to avoid traversing directions to find Q
        //all false/ unmarked
        vector<bool> upleftdiag(2*n - 1) , lowleftdiag(2*n - 1), cols(n); 
        
        recursiveNQueen(0, ans, n, upleftdiag, lowleftdiag, cols);
        
        return ans;
    }
};

//Compared to NQueen 1: Removed board and changed ans structure to int
//Also, no need to mark or unmark Q or keep rows structure, we are marking left cols, 
//and remaining cols will be unvisited, which row is marked handled by if condition