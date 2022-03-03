class Solution {
public:
    
    //Using Recursion
    int search(vector<int>& nums, int target) {
        return recursion_binary_search(nums,target,0,nums.size()-1);
    }
    
    int recursion_binary_search(vector<int>& nums, int& target, int start, int end){
        //base condition, when loop breaks
        if(start>end){
            return -1;
        }
        
        int mid = start + (end-start/2);
        
        //search right
        if(nums[mid]<target){
            return recursion_binary_search(nums, target, mid+1, end);
        }
        //searh left
        else if(nums[mid]>target){
            return recursion_binary_search(nums, target, start, mid-1);
        }
        
        //found
        return mid;
    }
    
    /*
    //Using iteration/loop:
    
    int search(vector<int>& nums, int target) {
        
        int index =-1;
        
        int left=0, right=nums.size()-1, mid;
        
        while(left<=right){
            mid = left + (right-left/2);
            
            if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target){
                right=right-1;
            }
            else{
                index=mid;
                break;
            }
        }
        
        return index;
    }*/
};