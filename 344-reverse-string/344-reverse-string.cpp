class Solution {
public:
    void reverseString(vector<char>& s) {
        
        //#1: Iterative
        // for(int l=0,r=s.size()-1 ;l<=r ;l++,r--){
        //     swap(s[l],s[r]);
        // }
        
        reverseStringTemp(s, 0, s.size()-1);
        
        return;
    }
    
    //#2: Recursive
    void reverseStringTemp(vector<char>& s, int l, int r) {
        
        if(l>=r)
            return;
            
        swap(s[l],s[r]);
        
        reverseStringTemp(s,++l,--r);
    }
};