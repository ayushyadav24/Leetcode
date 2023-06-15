//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod = 1000000007;
    long long int fib(long long int n, vector<long long int> &dp)
    {
        if(n<=1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = (fib(n-1, dp) + fib(n-2, dp))%mod;
    }
    long long int nthFibonacci(long long int n){
        vector<long long int>dp(n+1, -1);
        long long int ans = fib(n, dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends