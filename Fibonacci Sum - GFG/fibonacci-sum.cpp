//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int fibSum(long long int n){
        //code here
        int mod = 1e9+7;
        vector<long long int>dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod;
        }
        long long int sum = 0;
        for(int i=0; i<=n; i++)
        {
            sum += dp[i]%mod;
        }
        return sum%mod;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends