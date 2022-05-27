class Solution {
public:
    int numberOfSteps(int num) {
        
        int steps=0;
        
        while(num>0){
            if(num%2==0)
                num/=2;
            else
                num-=1;
            
            steps++;
        }
        
        return steps;
    }
    
    /*
        int numberOfSteps(int num) {
        if(num==0)
            return 0;
        if(num%2==0)
            return 1 + numberOfSteps(num/2);
        return 1 + numberOfSteps(num-1);
    }
    */
};