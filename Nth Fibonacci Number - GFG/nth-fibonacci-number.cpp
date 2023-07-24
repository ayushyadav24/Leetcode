//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mod = 1e9+7;
    // int utility(int n, vector<int> &dp)
    // {
    //      if(n==0 || n==1)
    //         return n;
        
    //     if(dp[n] != -1)
    //         return dp[n];
        
    //     dp[n] = (utility(n-1, dp)%mod + utility(n-2, dp)%mod)%mod;
        
    //     return dp[n];
    // }
    int nthFibonacci(int n){
        // code here
        long long prev2 = 0;
        long long prev1 = 1;
        for(int i=2; i<=n; i++)
        {
            long long curr = (prev1%mod + prev2%mod)%mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
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