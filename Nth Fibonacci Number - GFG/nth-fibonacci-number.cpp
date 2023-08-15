//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    int utility(int n, vector<int> &dp)
    {
        int mod = 1e9+7;
        if(n < 2)
            return n;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = (utility(n-1, dp)%mod+utility(n-2, dp)%mod)%mod;
    }
  public:
    int nthFibonacci(int n){
        // code here
        int mod = 1e9+7;
        vector<int>dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            dp[i] = (dp[i-1]%mod+dp[i-2]%mod)%mod;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends