class Solution {
public:
    
    //My recursion function
    void findSubsets(int i, vector<int>& valsf ,vector<int> &nums, vector<vector<int>> &ans)
    {
        //base case, if all traversed, add answer and return
        if(i<0)
        {
            ans.push_back(valsf);
            return;
        }
        
        //find subset without adding current element
        findSubsets(i-1, valsf, nums, ans);
        //add current element
        valsf.push_back(nums[i]);
        //find subsets after adding current element
        findSubsets(i-1, valsf, nums, ans);
        //remove current element
        valsf.pop_back();
    }
    
    //Given
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> valsf;
        int n = nums.size();
        
        findSubsets(n-1,valsf,nums,ans);
        
        return ans;
    }
};