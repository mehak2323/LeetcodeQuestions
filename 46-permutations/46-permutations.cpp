class Solution {
public:

    /*
    //Visited array O(n) space
    
    void permutation_util(vector<int>& nums, vector<bool>& visited, vector<int>& valsf ,vector<vector<int>> &ans){
        
        int n=nums.size();
        
        //Base case, if length of permutation reached, add, return
        if(valsf.size()==n){
            ans.push_back(valsf);
            return;
        }
        
        //Traverse array to pick unvisited value next
        for(int i=0; i<n; i++){
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
    }*/
    
    //Space optimized
    void permutation_util(vector<int>& nums, vector<vector<int>> &ans, int start){
        
        int n=nums.size();
        
        //Base case, if length of permutation reached, add, return
        if(start==n){
            ans.push_back(nums);
            return;
        }
        
        //Traverse array for rest of the values
        for(int i=start; i<n; i++){
            
            //Swap to visited side to consider rest permutation starting with it
            swap(nums[start], nums[i]);
            //Recursion
            permutation_util(nums, ans, start+1);
            //Swap back to restore
            swap(nums[start], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        //vector<int> valsf;
        //Array to keep track of included elements
        //vector<bool> visited(nums.size(),false);
        
        //Extra space solution
        //permutation_util(nums, visited, valsf ,ans);
        
        //Const space
        permutation_util(nums, ans, 0);
        return ans;
    }
};