//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int mod = (int)1e9+7;
    int helper(int ind, int sum, vector<int>& arr, vector<vector<int>> &dp)
    {
        // base case 
        if(ind == 0)
        {
            if(sum==0 && arr[0]==0)
                return 2;
            if(sum==0 || sum == arr[0])
                return 1;
            return 0;
        }
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        
        int notpick = helper(ind-1, sum, arr, dp);
        int pick = 0;
        if(arr[ind] <= sum)
            pick = helper(ind-1, sum-arr[ind], arr, dp);
            
        return dp[ind][sum] = (pick+notpick)%mod;
        
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totSum=0;
        for(int i=0; i<n; i++)
        {
            totSum += arr[i];
        }
        if((totSum-d) < 0)
            return 0;
    
        if((totSum-d) % 2 != 0)
            return 0;
        int target = (totSum - d);
        vector<vector<int>>dp(n, vector<int>(target/2+1, -1));
        return helper(n-1, target/2, arr, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends