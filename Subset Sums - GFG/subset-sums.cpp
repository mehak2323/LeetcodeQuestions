// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void sums(vector<int>& arr, int ind, int sumsf, vector<int>& ans){
        if(ind<0){
            ans.push_back(sumsf);
            return;
        }
        
        //Not Pick
        sums(arr,ind-1,sumsf,ans);
        //Pick
        sums(arr,ind-1,sumsf+arr[ind],ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        
        sums(arr,N-1,0,ans);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends