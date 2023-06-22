//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    int totsum = 0;
        for(int i=0; i<n; i++)
        {
            totsum += nums[i];
        }

        int k = totsum;

        vector<vector<bool>>dp(n, vector<bool>(k+1, 0));
        // base case initialisation
        for(int i=0; i<n; i++)
        {
            dp[i][0] = true;
        }
        if(nums[0] <= k)
            dp[0][nums[0]] = true;

        for(int i=1; i < n; i++)
        {
           for(int target = 1; target <= k; target++)
           {
               bool notTake = dp[i-1][target];
               bool take = false;
               if(target >= nums[i])
               {
                   take = dp[i-1][target-nums[i]];
               }
               dp[i][target] = (take || notTake);
           }
        }
        int mini= 1e9;
        for(int s1=0; s1<=k/2; s1++)
        {
            if(dp[n-1][s1] == true)
            {
                int diff = abs((k-s1) - s1);
                mini = min(mini, diff);
            }
        }
        return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends