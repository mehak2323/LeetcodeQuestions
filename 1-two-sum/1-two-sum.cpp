class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        vector<int> ans(2);
        
        /*
        unordered_map<int,int> umap;
        int remaining;
        
        for(int i=0; i<nums.size(); i++){
            remaining = target-nums[i];
            
            //If remaining already present
            if(umap.find(remaining) == umap.end()){
                ans[0]= pair[remaining].second;
                ans[1]= nums[i];
                break;
            }
            //Else add current element 
            else{
                pair[nums[i]]=i;
            }
        }
        */
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    ans[0]=i;
                    ans[1]=j;
                    break;
                }
            }
        }
        
        return ans;
    }
};

//nums = [3,2,4], target = 6
//    map=[(3,0),(2,1),(4,2)]
    
    