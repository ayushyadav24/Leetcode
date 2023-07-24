//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int mod = 1e9+7;
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        long long int prev2 = 1;
        long long int prev1 = 1;
        
        for(int i=2; i<=n; i++)
        {
            long long int cur = (prev1%mod + prev2%mod)%mod;
            prev2 = prev1;
            prev1 = cur;
        }
        return (int)prev1%mod;
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