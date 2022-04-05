class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstColHasZero = false;
        
        //Traverse the matrix and save row/col to change
        //by storing zeroes in first row and column
        for(int i=0; i<n; i++)
        {

            if(matrix[i][0]==0)
                firstColHasZero = true;
            
            //Starting from second column
            for(int j=1; j<m; j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        
        //Start from last row, last col till firsts to avoid
        //changing our saved zero values in first row and col
        for(int i=n-1; i>0; i--){
            for(int j=m-1; j>0; j--){
                if(matrix[0][j]==0||matrix[i][0]==0 ){
                    matrix[i][j]=0;
                }
            }
        }

        // See if the first row needs to be set to zero as well
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // See if the first column needs to be set to zero as well
        if (firstColHasZero) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
    
    
    /*
    //Kuch bhi, galat hi hai
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        bool changeFirstToZero = false;
        
        //Traverse the matrix and save row/col to change
        //by storing zeroes in first row and column
        for(int i=1; i<n; i++)
        {
            //Updating [0,0] if first column has zero but
            //later to avoid unwanted 0 in first row
            if(matrix[i][0]==0)
                changeFirstToZero = true;
            
            //Starting from second column to avoid marking [0,0]
            for(int j=1; j<m; j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        
        //Start from last row, last col till firsts to avoid
        //changing our saved zero values in first row and col
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(matrix[0][j]==0||matrix[i][0]==0 ){
                    matrix[i][j]=0;
                }
            }
        }

        if(changeFirstToZero)
            matrix[0][0]=0;
    }*/
};