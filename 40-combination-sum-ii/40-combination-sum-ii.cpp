class Solution {
public:
    

    void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        //Loop for indexes ahead as combinations starting from previous ones considered
        for (int i = ind; i < arr.size(); i++) {
            //If we already picked the next element in combination and 
            //the current loop index has same value as the one we picked then 
            //we'll have duplicates (eg- arr=[1,2,2,3], prev was [1], in this recursion in for loop, 
            //we picked 2, we got [1,2] now next for index is also 2, we dont pick [1,2] again)
            if (i > ind && arr[i] == arr[i - 1]) continue;
            
            //if item exceed target, next ones will exceed as it's sorted
            if (arr[i] > target) break;
            
            //Pick and recur
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        //Sort to help in avoiding duplicate and answers in order
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};


/*

//Combination 1 answer with index+1 if picking and using set to remove duplicates

void subsequence(int idx, vector<int>& ss, int target, vector<int>& candidates, set<vector<int>>& s)
    {
        if(idx == candidates.size())
        {
            if(target == 0)
                s.insert(ss);
            return;
        }
        if(candidates[idx] <= target)
        {
            ss.push_back(candidates[idx]);
            subsequence(idx+1, ss, target-candidates[idx], candidates, s);
            ss.pop_back();
        }
        subsequence(idx+1, ss, target, candidates, s);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ss;
        set<vector<int>> s;
        sort(candidates.begin(), candidates.end());
        subsequence(0, ss, target, candidates, s);
        for(auto &it : s)
            res.push_back(it);
        return res;
    }
*/