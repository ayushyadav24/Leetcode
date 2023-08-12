//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int utility(int ind, int k, vector<int>&arr, vector<int> &dp)
    {
        // base case
        if(ind == 0)
            return 0;
            
        if(dp[ind] != -1)
            return dp[ind];
        
        int minStep = INT_MAX;
        for(int j=1; j<=k; j++)
        {
            if(ind-j >=0)
            {
                int jumps = utility(ind-j, k, arr, dp) + abs(arr[ind] - arr[ind-j]);
                minStep = min(minStep, jumps);
            }
        }
        return dp[ind] = minStep;
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n+1, 0);
        return utility(n-1, k, height, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends