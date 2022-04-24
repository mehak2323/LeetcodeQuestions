class Solution {
public:
    
    //My function
    void findSubset(vector<int>& nums, int ind, int& n, vector<int>& valsf, vector<vector<int>>& ans){
        
        //No need for base case as already handled below
        // if(ind==n){
        //     ans.push_back(valsf);
        //     return;
        // }
        
        //First push data to ans to get empty subset and in each call
        ans.push_back(valsf);
        
        //Traverse rest of arr to make subests of current size then increase
        for(int i=ind; i<n; i++){
            
            //To avoid duplicates
            if(i>ind && nums[i]==nums[i-1]) continue;
            
            //Take element and next call
            valsf.push_back(nums[i]);
            findSubset(nums,i+1,n,valsf,ans);
            valsf.pop_back();
        }
        
    }
        
    //Given function
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> valsf; //value so far
        
        //Sorting to identify duplicates
        sort(nums.begin(), nums.end());
        
        findSubset(nums,0,n,valsf,ans);
        
        return ans;
    }
};

/*
TC: 2^n * n + n log n
SC: 2^n* k (k = avg subset size) + n (auxiliary space of recursion)
*/