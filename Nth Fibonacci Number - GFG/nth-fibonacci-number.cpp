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
        vector<int>dp(n+1, -1);
        return utility(n, dp);
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