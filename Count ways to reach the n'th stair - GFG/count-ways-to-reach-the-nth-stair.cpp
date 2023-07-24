//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int mod = 1e9+7;
    public:
    
    int help(int n, vector<int>&dp)
    {
        if(n<2)
            return 1;
            
        if(dp[n] != -1)
            return dp[n]%mod;
            
        return dp[n] = (help(n-1, dp)%mod + help(n-2, dp)%mod)%mod;
    }
    
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        vector<int>dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod;
        }
        return dp[n]%mod;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends