class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans(numRows);
        
        //using resize function, memory less than 68.62%, 6.5MB
        for(int i=0 ; i<numRows; i++)
        {
            ans[i].resize(i+1);
            ans[i][0]= ans[i][i]=1;
            for(int j=1; j<i; j++)
            {
                ans[i][j]=ans[i-1][j-1]+ ans[i-1][j];               
            }
        }  
        
        /*
        //without resize, just pushback, memory less than 31.43%, 6.6MB
        for(int i=0 ; i<numRows; i++)
        {
            for(int j=0; j<i+1; j++)
            {
                if(j==0 || j==i)
                    ans[i].push_back(1);
                else
                    ans[i].push_back(ans[i-1][j-1]+ ans[i-1][j]);               
            }
        }
        */
        return ans;
        
    }
};