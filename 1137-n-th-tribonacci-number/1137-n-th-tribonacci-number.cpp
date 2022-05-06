class Solution {
public:
    int tribonacci(int n) {
        
        //initializing first three
        int first=0, second=1, third=1, current;
        
        //base case, before we start calculation
        if(n<2) return n;
        if(n==2) return 1;
        
        for(int i=3; i<=n; i++){
            //find next
            current = first + second + third;
            //update previous
            first = second;
            second = third;
            third = current;
        }
        
        return current;
    }
};