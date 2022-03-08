class Solution {
public:
    
    bool isPowerOfTwo(int n) {

        if(n<=0){
            return false;
        }
        
        int power = log2(n);
        //cout<<power<<"\n";
        
        if(pow(2,power)==n)
            return true;
        return false; 
    }
    
    
    /*
    //Didnt check yet
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        if(n==1)
            return true;
        return isPowerOfTwoUTIL(n,2); 
    }
    
    //Test with cases
    bool isPowerOfTwoUTIL(int n, int curr){
        if(curr==n)
            return true;
        if(curr>n)
            return false;
        
        return isPowerOfTwoUTIL(n,curr*2);      
    }*/
};