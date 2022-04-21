class Solution {
public:
    
    /*
    //Striver's function
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds) {
        if(ind == arr.size()) {
            if(target == 0) {
                ans.push_back(ds); 
            }
            return; 
        }
        // pick up the element 
        if(arr[ind] <= target) {
            ds.push_back(arr[ind]); 
            findCombination(ind, target - arr[ind], arr, ans, ds); 
            ds.pop_back(); 
        }
        
        findCombination(ind+1, target, arr, ans, ds); 
        
    }*/
    
    //My function
    void combinations(vector<int>& candidates, int& target, vector<int>& comb, vector<vector<int>>& ans, int sumsf, int ind){
        //helper case
        if(sumsf>target)
            return;
        //base case
        if(ind==candidates.size()){
            if(sumsf==target)
                ans.push_back(comb);
            return;
        }
        
        //Not pick
        combinations(candidates,target,comb,ans,sumsf,ind+1);
        //Pick
        comb.push_back(candidates[ind]);
        sumsf+=candidates[ind];
        combinations(candidates,target,comb,ans,sumsf,ind);
        
        comb.pop_back();
     }
    
    //Given
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> comb;
        
        //findCombination(0, target, candidates, ans, ds);
        combinations(candidates,target,comb,ans,0,0);
        
        return ans;
    }
};




/*

//An embarrassment, idk what i was thinking... oh right, I wasn't

//My function
    void combinations(vector<int>& candidates, int& target, vector<int>& comb, vector<vector<int>>& ans, int sumsf){
        
        //helper case
        if(sumsf>target)
            return;
        //base case
        if(sumsf==target){
            ans.push_back(comb);
            return;
        }
        
        int n=candidates.size();
        
        //Recur for all items in array
        for(int i=0; i<n; i++){
            
            //Add current element
            comb.push_back(candidates[i]);
            sumsf+=candidates[i];
            
            //Recursion
            combinations(candidates,target,comb,ans,sumsf);
            
            //Remove current element after it's recursion cycle for next one
            sumsf-=candidates[i];
            comb.pop_back();
        }
        
    }
    
*/