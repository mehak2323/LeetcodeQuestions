class Solution {
public:
    
    void permutation_util(vector<int>& nums, vector<bool>& visited, vector<int>& valsf ,vector<vector<int>> &ans){
        
        int n=nums.size();
        
        //Base case, if length of permutation reached, add, return
        if(valsf.size()==n){
            ans.push_back(valsf);
            return;
        }
        
        //Traverse array to pick unvisited value next
        for(int i=0; i<n; i++){
            
            //If duplicate with unvisited element
            if(i>0 && nums[i]==nums[i-1] && visited[i-1]==false) continue;
            
            if(!visited[i]){
                
                //Mark visited and add in permutation
                visited[i]=true;
                valsf.push_back(nums[i]);
                
                //Recursion
                permutation_util(nums, visited, valsf ,ans);
                
                //Unvisit and remove current
                visited[i]=false;
                valsf.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> valsf;
        //Array to keep track of included elements
        vector<bool> visited(nums.size(),false);
        
        //Sort for finding duplicates
        sort(nums.begin(),nums.end());
        
        permutation_util(nums, visited, valsf ,ans);
        return ans;
    }
};