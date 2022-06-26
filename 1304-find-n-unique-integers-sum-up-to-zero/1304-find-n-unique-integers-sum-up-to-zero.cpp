class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int> ans(n,0);
        if(n==1) return ans;
        int mid=n/2;
        
        //Add negatives
        int curr = -1;
        for(int i=mid-1; i>=0; i--){
            ans[i] = curr--;
        }
        
        //If odd, add zero
        if(n%2!=0) {
            ans[mid]=0;
            mid=mid+1;
        }
        
        //Add positives
        curr=1;
        for(int i=mid; i<n; i++){
            ans[i] = curr;
            curr++;
        }
        
        return ans;
    }
};