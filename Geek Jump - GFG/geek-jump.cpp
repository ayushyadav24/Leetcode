//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int utility(vector<int>& height, int ind, vector<int> &dp)
    {
        // base case
        if(ind == 0)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int oneStep = utility(height, ind-1, dp) + abs(height[ind] - height[ind-1]);
        
        int twoStep = INT_MAX;
        if(ind > 1)
            twoStep = utility(height, ind - 2, dp) + abs(height[ind] - height[ind-2]);
        
        return dp[ind] = min(oneStep, twoStep);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n+1, 0);
        dp[0] = 0;
        for(int i=1; i<=n; i++)
        {
            int oneStep = dp[i-1] + abs(height[i] - height[i-1]);
            int twoStep = INT_MAX;
            if(i>1)
                twoStep = dp[i-2] + abs(height[i] - height[i-2]);
            
            dp[i] = min(oneStep, twoStep);
        }
        return dp[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends