class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans(rowIndex+1);
        
        for(int i=0; i<=rowIndex; i++){
            ans[0]=ans[i]=1;
    
            for(int j=i-1; j>0; j--){
                ans[j] = ans[j-1] + ans[j];
            }
        }

        return ans;
    }
};