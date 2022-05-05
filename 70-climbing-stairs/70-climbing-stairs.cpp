class Solution {
public:
    int climbStairs(int n) {
        
        //Since recursion relation will be f(n-1) + f(n-2)
        //which is like fibonacci, do bottom up fibonacci computing
        
        //base case
        if(n<=2) return n;
        
        //1 way to reach 1st stair, 2 ways for 2nd stair
        int prev1=2, prev2=1, curr_ways=0;
        
        //Loop for remaining stairs
        for(int i=3; i<=n; i++){
            //current n ways is sum of previous two
            curr_ways = prev1 + prev2;
            //update previous two
            prev2 = prev1;
            prev1 = curr_ways;
        }
        
        return curr_ways;
    }
};