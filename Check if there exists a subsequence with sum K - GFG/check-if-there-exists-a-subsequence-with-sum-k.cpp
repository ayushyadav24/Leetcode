//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool combination(vector<int>&arr, int target, int sum, int index, vector<int>&temp)
    {
        if(sum == target)
        {
            return true;
        }
        
        for(int i=index; i<arr.size(); i++)
        {
            // ignore duplicates
            if(i > index && arr[i]==arr[i-1])
            {
                continue;
            }
            
            if(sum + arr[i] > target)
            {
                break;
            }
            
            temp.push_back(arr[i]);
            if(combination(arr, target, sum+arr[i], i+1, temp))
                return true;
            temp.pop_back();
        }
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int target) {
        // Code here
        sort(arr.begin(), arr.end());
        vector<int>temp;
        return combination(arr, target, 0, 0, temp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends