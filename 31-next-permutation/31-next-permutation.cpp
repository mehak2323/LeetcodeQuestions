class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        //eg- 243 5 9861 =>  243 6 1589
        int n = nums.size() , i; 
        
        //Find if descending no. from back, swap with 
        //smallest greater than it in later array
        
        //traverse from back to front
        for(i= n-1; i>0; i--)
        {
            //if a descending element found
            if(nums[i-1]<nums[i])
            {
                int minInd=i, j;
                //find smallest greater than descending in further array
                for(j=i; j<n; j++)
                {
                    if(nums[j]<=nums[minInd] && nums[j]>nums[i-1])
                    {
                        minInd=j;
                    }      
                }
                swap(nums[i-1],nums[minInd]);
                //after swap break, i will be index till which we reverse
                break;
            }
        }
        
        //Reverse array till descending element position, Or the whole
        for(int last=n-1 ; i<=last; i++ ,last--)
        {
            swap(nums[i], nums[last]);
        }
        
    }
};