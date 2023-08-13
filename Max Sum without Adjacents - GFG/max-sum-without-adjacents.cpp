//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private:
    int utility(int ind, int arr[], vector<int> &dp)
    {
        // base case
        if(ind == 0)
            return arr[0];
            
        if(ind < 0)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int np = utility(ind-1, arr, dp);
        int pick = arr[ind] + utility(ind-2, arr, dp);
            
        return dp[ind] = max(np, pick);
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n+1, 0);
	    dp[0] = arr[0];
	    for(int i=1; i<n; i++)
	    {
	        int np = dp[i-1];
	        int p = arr[i];
	        if(i > 1)
	            p += dp[i-2];
	        dp[i] = max(p, np);
	    }
	    return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends