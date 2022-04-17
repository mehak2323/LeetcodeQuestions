class Solution {
public:
    
    //My recursion function
    void findPermutation(int i, int &n, string& s, string &valsf, vector<string> &ans){
        
        //base case, if all traversed, add answer and return
        if(i>=n){
            ans.push_back(valsf);
            return;
        }
        
        if(isdigit(s[i])){
            //add current element
            valsf.push_back(s[i]);
            findPermutation(i+1, n, s, valsf, ans);
        }
        else{
            //find permutation after lowercasing current element
            valsf.push_back(tolower(s[i]));
            findPermutation(i+1, n, s, valsf, ans);
            //remove current element
            valsf.pop_back();
            
            //find permutation after capitalizing current element
            valsf.push_back(toupper(s[i]));
            findPermutation(i+1, n, s, valsf, ans);
        }
        //remove current element
        valsf.pop_back();
    }
    
    //Given
    vector<string> letterCasePermutation(string s) {
        
        int n = s.length();
        string valsf;
        vector<string> ans;
        
        findPermutation(0, n, s, valsf, ans);
        
        return ans;
    }
};