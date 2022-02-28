class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        //ans for one string is string itself 
        string ans=strs[0], currAns="";
        int n=strs.size();
        
        //Loop in the vector, compare 2 consecutive strings
        for(int i=0; i<n-1; i++){
            
            //Find minimum length of current two strings for j loop
            int minLen = min(strs[i].size(), strs[i+1].size());
            
            //Loop in current two strings to compare
            for(int j=0; j<minLen; j++){
                //If unequal, break, else find common
                if(strs[i][j]!=strs[i+1][j]){
                    break;
                }
                currAns+= strs[i][j];
            }
            
            //If shorter length found
            if(i==0 || currAns.size()<ans.size()){
                ans=currAns;
            }
            
            currAns="";
        }
        
        return ans;
    }
};