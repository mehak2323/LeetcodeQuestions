class Solution {
public:
    
    void recur(string &anssf, int curr_dig, string &digits, vector<string>& ans, vector<string>& buttons){
        
        //If answer with length of digits found, add answer, return
        if(curr_dig == digits.length()){
            ans.push_back(anssf);
            return;
        }
        
        //Iterate in all letters of current digit, add letter and increase length for recursion
        for(int i=0; i<buttons[digits[curr_dig]-'0'].length(); i++){
            
            //Add current digits' current letter
            anssf+= buttons[digits[curr_dig]-'0'][i];
            //Recur for remaining length
            recur(anssf, curr_dig+1, digits,ans,buttons);
            //Remove the current letter for next letter of current digit
            anssf.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        
        //If empty
        if(digits.length()==0){
            return ans;
        }
        
        string anssf=""; //ans string so far
        
        //Buttons, mapping digit to alphabets
        vector<string> buttons = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        recur(anssf,0,digits,ans,buttons);
        
        return ans;
    }
};