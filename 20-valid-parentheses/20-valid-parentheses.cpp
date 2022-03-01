class Solution {
public:
    bool isValid(string s) {
        
        int j = 0, n=s.size();
        
        //If length is odd, ans is false
        if(n%2!=0)
            return false;
        
        bool ans = true;
        vector<char> seq(n);
        
        for(int i=0; i<n; i++){
            //If open bracket, add in list
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                seq[j]=s[i];
                j++;
            }
            //If closed bracket
            else{
                //If no opened bracket, ans is false
                if(j==0){
                    ans=false;
                    break;
                }
                //If last opened matches current closing bracket, remove one opened
                else if( (seq[j-1]=='(' && s[i]==')')||(seq[j-1]=='[' && s[i]==']')||
                        (seq[j-1]=='{' && s[i]=='}') ){
                    j--;
                }
                //If last opened not same as current closing, ans false
                else{
                    ans=false;
                    break;
                }
            }
        }
        
        //If some opened brackets remain
        if(j>0){
            ans=false;
        }
        
        return ans;
    }
    
    /*
    //Only for number of brackets not order
    bool isValid(string s) {
        int curved=0, squared=0, curly=0;
        bool ans = true;
        
        for(int i=0; i<s.size(); i++){
            switch(s[i]){
                case '(': curved++; break;
                case '[': squared++; break;
                case '{': curly++; break;
                case ')': curved--; break;
                case ']': squared--; break;
                case '}': curly--; break; 
            }
            if(curved<0 || squared<0 || curly<0){
                ans=false;
                break;
            }
        }
        if(curved>0 || squared>0 || curly>0){
            ans=false;
        }
        
        return ans;
    }*/
};