class Solution {
public:
    /*
    //Using log (0 ms, 6.1 MB)
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
    */
    
    //Recursion with remainder divident method
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        if(n==1)
            return true;
        if(n%2==0)
            return isPowerOfTwo(n/2);
        else
            return false;
    }
    

    /*
    //Recursion, causes error due to signed integer overflow
    //1073741824 * 2 cannot be represented in type 'int'
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        if(n==1)
            return true;
        return isPowerOfTwoUTIL(n,2); 
    }
    
    bool isPowerOfTwoUTIL(int n, int curr){
        if(curr==n)
            return true;
        if(curr>n)
            return false;
        
        return isPowerOfTwoUTIL(n,curr*2);      
    }*/
};