class Solution {
public:
    
    /*
    //Return int method
    int numDecodeRecur2(int ind, string &s){
        
        //base case
        if(ind==s.length()){
            return 1;
        }
        
        int one_dig=0, two_dig=0;
        
        //One digit
        if(s[ind]!='0'){
            one_dig = numDecodeRecur2(ind+1, s);
        }
        //Two digit
        if((s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6')) && ind+1<s.length()){
            two_dig = numDecodeRecur2(ind+2, s);
        }
        
        return one_dig + two_dig; 
    }
    
    //Return void method
    void numDecodeRecur(int ind, string &s, int &ans){
        
        //base case
        if(ind==s.length()){
            ans+=1;
            return;
        }
        
        //One digit
        if(s[ind]!='0'){
            numDecodeRecur(ind+1, s, ans);
        }
        //Two digit
        if((s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6')) && ind+1<s.length()){
            numDecodeRecur(ind+2, s, ans);
        }
    }*/
    
    //Memoization
    int numDecodeRecur2(int ind, string &s, vector<int> &dp){
        
        //base case
        if(ind==s.length()){
            return 1;
        }
        
        if(dp[ind]!=-1){
            return dp[ind];
        }
        else{
            
            int one_dig=0, two_dig=0;

            //One digit
            if(s[ind]!='0'){
                one_dig = numDecodeRecur2(ind+1, s, dp);
            }
            //Two digit
            if((s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6')) && ind+1<s.length()){
                two_dig = numDecodeRecur2(ind+2, s, dp);
            }

            return dp[ind] = one_dig + two_dig;
        }
    }
    
    int numDecodings(string s) {
        
        int ans=0;
        vector<int> dp(s.length(), -1);
        ans = numDecodeRecur2(0, s, dp);
        
        //numDecodeRecur(0, s, ans);
        //ans = numDecodeRecur2(0, s);
        return ans;
    }
};

//TLE "111111111111111111111111111111111111111111111" using recursion